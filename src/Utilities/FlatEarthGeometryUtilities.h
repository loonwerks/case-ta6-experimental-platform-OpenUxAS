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

#ifndef FLAT_EARTH_GEOMETRY_UTILITIES_H
#define FLAT_EARTH_GEOMETRY_UTILITIES_H

#include "afrl/cmasi/AbstractGeometry.h"
#include "afrl/cmasi/Circle.h"
#include "afrl/cmasi/Location3D.h"
#include "afrl/cmasi/Polygon.h"
#include "afrl/cmasi/Rectangle.h"

#include "FlatEarth.h"

namespace uxas
{
namespace common
{
namespace utilities
{

class FlatEarthGeometryUtilities
{

public:

    FlatEarthGeometryUtilities();

    virtual ~FlatEarthGeometryUtilities();

public:

    static bool locationWithinCircle
    (const std::shared_ptr<afrl::cmasi::Location3D>& location, const std::shared_ptr<afrl::cmasi::Circle>& circle);

    static bool locationWithinPolygon
    (const std::shared_ptr<afrl::cmasi::Location3D>& location, const std::shared_ptr<afrl::cmasi::Polygon>& polygon);

    static bool locationWithinRectangle
    (const std::shared_ptr<afrl::cmasi::Location3D>& location, const std::shared_ptr<afrl::cmasi::Rectangle>& rectangle);

private:

    static bool linesIntersect
        (double v1x1, double v1y1, double v1x2, double v1y2, double v2x1, double v2y1, double v2x2, double v2y2);

};

}; //namespace utilities
}; //namespace common
}; //namespace uxas

#endif /* FLAT_EARTH_GEOMETRY_UTILITIES_H */
