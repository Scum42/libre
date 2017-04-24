@echo off

if "%1" == "-r" rmdir b_vs2015 /Q /S
call build-for-vs2015
start b_vs2015\Libre.sln