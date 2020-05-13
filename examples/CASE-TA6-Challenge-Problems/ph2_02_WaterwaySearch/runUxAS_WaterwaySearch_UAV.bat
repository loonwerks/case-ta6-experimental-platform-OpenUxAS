mkdir RUNDIR_WaterwaySearch_UAV
cd RUNDIR_WaterwaySearch_UAV
rmdir /S /Q datawork
rmdir /S /Q log
..\..\..\build\uxas.exe -cfgPath ..\cfg_WaterwaySearch_UAV.xml

