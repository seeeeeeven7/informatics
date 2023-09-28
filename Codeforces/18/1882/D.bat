@echo off
:loop
echo Running D_make.exe
D_make.exe

echo Running D.exe
D.exe

goto loop

:end
echo Batch processing completed.
