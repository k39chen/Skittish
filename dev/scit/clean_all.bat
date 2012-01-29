:: Description:
::   Deletes garbage files produced by compiler. Place this in the same directory as your *.vcxproj file
::
:: Author: Kevin Chen
@echo off

:: deleting compiler files
echo Deleting compiler files...
del Debug\*.obj
del Debug\*.res
del Debug\*.manifest
del Debug\*.idb
del Debug\*.pdb
del Debug\*.tlog

:: deleting user files
echo Deleting user files...
del *.user

:: deleting project files
echo Deleting project files...
del ..\*.sdf

echo Recursively deleting IPCH directory...
FOR /F "tokens=*" %%G IN ('DIR /B /AD /S ..\ipch') DO RMDIR /S /Q "%%G"
rmdir ..\ipch