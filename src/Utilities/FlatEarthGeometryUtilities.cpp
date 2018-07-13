/**************************************************************************
  Copyright (c) 2018 Rockwell Collins. Developed with the sponsorship
  of the Defense Advanced Research Projects Agency (DARPA).

  Permission is hereby granted, free of charge, to any person
  obtaining a copy of this data, including any software or models
  in source or binary form, as well as any drawings,
  specifications, and documentation (collectively "the Data"), to
  deal in the Data without restriction, including without
  limitation the rights to use, copy, modify, merge, publish,
  distribute, sublicense, and/or sell copies of the Data, and to
  permit persons to whom the Data is furnished to do so, subject to
  the following conditions:

  The above copyright notice and this permission notice shall be
  included in all copies or substantial portions of the Data.

  THE DATA IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
  OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS, SPONSORS,
  DEVELOPERS, CONTRIBUTORS, OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
  CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
  CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
  CONNECTION WITH THE DATA OR THE USE OR OTHER DEALINGS IN THE
  DATA.
 **************************************************************************/

#include "FlatEarthGeometryUtilities.h"

#include <cmath>
#include <memory>

#include "avtas/lmcp/Object.h"

#include "afrl/cmasi/AbstractGeometry.h"
#include "afrl/cmasi/Circle.h"
#include "afrl/cmasi/Location3D.h"
#include "afrl/cmasi/Polygon.h"
#include "afrl/cmasi/Rectangle.h"

#include "FlatEarth.h"

#include "UxAS_Log.h"

namespace uxas
{
namespace common
{
namespace utilities
{

FlatEarthGeometryUtilities::FlatEarthGeometryUtilities
()
{ };

FlatEarthGeometryUtilities::~FlatEarthGeometryUtilities
()
{ };

// bool
// FlatEarthGeometryUtilities::locationWithinAbstractGeometry
// (const afrl::cmasi::Location3D& location,
//  const afrl::cmasi::AbstractGeometry& geometry)
// {
//     if (afrl::cmasi::isCircle((std::shared_ptr<avtas::lmcp::Object>&) geometry)) {
//         //auto circle = std::static_pointer_cast<afrl::cmasi::Circle>(geometry);
//         return locationWithinCircle(location, circle);
//     } else if (afrl::cmasi::isPolygon((std::shared_ptr<avtas::lmcp::Object>&) geometry)) {
//         auto polygon = std::static_pointer_cast<afrl::cmasi::Polygon>(geometry);
//         return locationWithinPolygon(location, polygon);
//     } else if (afrl::cmasi::isRectangle((std::shared_ptr<avtas::lmcp::Object>&) geometry)) {
//         auto rectangle = std::static_pointer_cast<afrl::cmasi::Rectangle>(geometry);
//         return locationWithinRectangle(location, rectangle);
//     } else {
//         UXAS_LOG_ERROR("FlatEarthGeometryUtilities::locationWithinAbstractGeometry: encountered unknown geometry type");
//     }
//     return false;
// }

bool
FlatEarthGeometryUtilities::locationWithinCircle
(const std::shared_ptr<afrl::cmasi::Location3D>& location,
 const std::shared_ptr<afrl::cmasi::Circle>& circle)
{
    auto flatEarth = new FlatEarth();
    flatEarth->Initialize(location->getLatitude(), location->getLongitude());

    afrl::cmasi::Location3D* const centerPoint = circle->getCenterPoint();
    double radius = (double) circle->getRadius();

    double distance = flatEarth->dGetLinearDistance_m_Lat1Long1_deg_To_Lat2Long2_deg
        (centerPoint->getLatitude(), centerPoint->getLongitude(), location->getLatitude(), location->getLongitude());

    return distance <= radius;
}

// This implements the classical "Point-in-Polygon" algorithm as described
// here: https://en.wikipedia.org/wiki/Point_in_polygon
bool
FlatEarthGeometryUtilities::locationWithinPolygon
(const std::shared_ptr<afrl::cmasi::Location3D>& location,
 const std::shared_ptr<afrl::cmasi::Polygon>& polygon)
{
    auto boundaryPoints = polygon->getBoundaryPoints();

    // Count the number of times a ray from the location intersects a side of
    // the polygon where a side is defined as an adjacent pair of points.
    unsigned intersections = 0;

    // Manufacture the ray by making its points be along a horizontal line.
    // The location is (0 easting, 0 northing) after initializing our flat
    // earth calculator at the location;
    auto flatEarth = new FlatEarth();
    flatEarth->Initialize(location->getLatitude(), location->getLongitude());

    // To remember to consider the final side as the last and first points,
    // prime the pump with the last point in the list.
    double previousLatitude = boundaryPoints[boundaryPoints.size() - 1]->getLatitude();
    double previousLongitude = boundaryPoints[boundaryPoints.size() - 1]->getLongitude();
    double previousNorthing = 0;
    double previousEasting = 0;
    flatEarth->ConvertLatLong_degToNorthEast_m(previousLatitude, previousLongitude, previousNorthing, previousEasting);

    for (unsigned index = 0; index < boundaryPoints.size(); ++index)
    {
        double currentLatitude = boundaryPoints[index]->getLatitude();
        double currentLongitude = boundaryPoints[index]->getLongitude();
        double currentNorthing = 0.0;
        double currentEasting = 0.0;
        flatEarth->ConvertLatLong_degToNorthEast_m(currentLatitude, currentLongitude, currentNorthing, currentEasting);
        if (linesIntersect(0.0, 0.0, 1.0, 0.0, previousEasting, previousNorthing, currentEasting, currentNorthing))
        {
            ++intersections;
        }
    }
    
    // If the number of intersections is even, the location is outside the
    // polygon.  If it's odd, the location is inside the polygon.
    return (intersections & 1);
}

bool
FlatEarthGeometryUtilities::locationWithinRectangle
(const std::shared_ptr<afrl::cmasi::Location3D>& location,
 const std::shared_ptr<afrl::cmasi::Rectangle>& rectangle)
{
    // First generate a flat earth calculator centered at the rectangle center
    auto rectangleCenter = rectangle->getCenterPoint();
    auto flatEarth = new FlatEarth();
    flatEarth->Initialize(rectangleCenter->getLatitude(), rectangleCenter->getLongitude());

    // And find the easting and northing of the location from the rectangle center
    double locationEasting = 0.0;
    double locationNorthing = 0.0;
    flatEarth->ConvertLatLong_degToNorthEast_m(location->getLatitude(), location->getLongitude(), locationNorthing, locationEasting);

    // To ease the calculations, rather than rotating the rectangle, instead
    // "un-rotate" the location so it's in the same coordinate system as the
    // unrotated rectangle.
    double rotation = rectangle->getRotation();
    double sinUnrot = sin(-rotation);
    double cosUnrot = cos(-rotation);
    double unrotatedLocationEasting = (cosUnrot * locationEasting) - (sinUnrot * locationNorthing);
    double unrotatedLocationNorthing = (sinUnrot * locationEasting) + (cosUnrot * locationNorthing);

    double halfHeight = rectangle->getHeight() / 2.0;
    double halfWidth = rectangle->getWidth() / 2.0;

    if ((-halfHeight <= unrotatedLocationNorthing) && (unrotatedLocationNorthing <= halfHeight)
        && (-halfWidth <= unrotatedLocationEasting) && (unrotatedLocationEasting <= halfWidth))
    {
        return true;
    }

    return false;
}

// Algoritm taken from StackOverflow
// https://stackoverflow.com/questions/217578/how-can-i-determine-whether-a-2d-point-is-within-a-polygon
bool
FlatEarthGeometryUtilities::linesIntersect
(double v1x1, double v1y1, double v1x2, double v1y2,
 double v2x1, double v2y1, double v2x2, double v2y2)
{
    double d1, d2;
    double a1, a2, b1, b2, c1, c2;

    // Convert vector 1 to a line (line 1) of infinite length.
    // We want the line in linear equation standard form: A*x + B*y + C = 0
    // See: http://en.wikipedia.org/wiki/Linear_equation
    a1 = v1y2 - v1y1;
    b1 = v1x1 - v1x2;
    c1 = (v1x2 * v1y1) - (v1x1 * v1y2);

    // Every point (x,y), that solves the equation above, is on the line,
    // every point that does not solve it, is not. The equation will have a
    // positive result if it is on one side of the line and a negative one 
    // if is on the other side of it. We insert (x1,y1) and (x2,y2) of vector
    // 2 into the equation above.
    d1 = (a1 * v2x1) + (b1 * v2y1) + c1;
    d2 = (a1 * v2x2) + (b1 * v2y2) + c1;

    // If d1 and d2 both have the same sign, they are both on the same side
    // of our line 1 and in that case no intersection is possible. Careful, 
    // 0 is a special case, that's why we don't test ">=" and "<=", 
    // but "<" and ">".
    if (d1 > 0 && d2 > 0) return false;
    if (d1 < 0 && d2 < 0) return false;

    // The fact that vector 2 intersected the infinite line 1 above doesn't 
    // mean it also intersects the vector 1. Vector 1 is only a subset of that
    // infinite line 1, so it may have intersected that line before the vector
    // started or after it ended. To know for sure, we have to repeat the
    // the same test the other way round. We start by calculating the 
    // infinite line 2 in linear equation standard form.
    a2 = v2y2 - v2y1;
    b2 = v2x1 - v2x2;
    c2 = (v2x2 * v2y1) - (v2x1 * v2y2);

    // Calculate d1 and d2 again, this time using points of vector 1.
    d1 = (a2 * v1x1) + (b2 * v1y1) + c2;
    d2 = (a2 * v1x2) + (b2 * v1y2) + c2;

    // Again, if both have the same sign (and neither one is 0),
    // no intersection is possible.
    if (d1 > 0 && d2 > 0) return false;
    if (d1 < 0 && d2 < 0) return false;

    // If we get here, only two possibilities are left. Either the two
    // vectors intersect in exactly one point or they are collinear, which
    // means they intersect in any number of points from zero to infinite.
    // We consider colinear to be an intersection at every point
    if ((a1 * b2) - (a2 * b1) == 0.0f) return true;

    // If they are not collinear, they must intersect in exactly one point.
    return true;
}

}; //namespace utilities
}; //namespace common
}; //namespace uxas
