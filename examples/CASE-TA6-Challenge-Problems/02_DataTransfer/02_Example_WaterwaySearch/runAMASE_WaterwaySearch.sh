here=$PWD;

cd ../../../../../OpenAMASE/OpenAMASE;
java -Xmx2048m -splash:./data/amase_splash.png -classpath ./dist/*:./lib/*  avtas.app.Application --config config/amase --scenario "../../OpenUxAS/examples/CASE-TA6-Challenge-Problems/02_DataTransfer/02_Example_WaterwaySearch/Scenario_WaterwaySearch.xml";
cd "$here";

