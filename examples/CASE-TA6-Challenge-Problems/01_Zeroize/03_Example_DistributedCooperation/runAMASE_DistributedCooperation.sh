here=$PWD;

cd ../../../../../OpenAMASE/OpenAMASE;
java -Xmx2048m -splash:./data/amase_splash.png -classpath ./dist/*:./lib/*  avtas.app.Application --config config/amase --scenario "../../OpenUxAS/examples/CASE-TA6-Challenge-Problems/01_Zeroize/03_Example_DistributedCooperation/Scenario_DistributedCooperation.xml";
cd "$here";

