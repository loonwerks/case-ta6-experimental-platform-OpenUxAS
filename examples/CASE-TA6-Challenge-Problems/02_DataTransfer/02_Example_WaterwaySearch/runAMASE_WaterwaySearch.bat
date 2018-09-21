pushd ..\..\..\..\..\OpenAMASE\OpenAMASE
java -Xmx2048m -splash:data\amase_splash.png -cp dist\*;lib\*  avtas.app.Application --config config\amase --scenario "..\..\OpenUxAS\examples\CASE-TA6-Challenge-Problems\01_Zeroize\02_Example_WaterwaySearch\Scenario_WaterwaySearch.xml"
popd

