@echo off
pushd %~dp0
set PATH=%PATH%;%APPDATA%\cygwin-x86\cygwin\bin
bds.exe SLABProject.cbproj
exit
