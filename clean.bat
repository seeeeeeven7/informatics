@echo off
for /r %%i in (*.exe) do (
    del "%%i"
)
