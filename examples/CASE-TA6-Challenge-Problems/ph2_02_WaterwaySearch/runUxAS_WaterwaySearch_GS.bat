mkdir RUNDIR_WaterwaySearch_GS
cd RUNDIR_WaterwaySearch_GS
rmdir /S /Q datawork
rmdir /S /Q log
..\..\..\build\uxas.exe -cfgPath ..\cfg_WaterwaySearch_GS.xml

