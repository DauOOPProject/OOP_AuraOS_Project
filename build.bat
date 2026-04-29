@echo off
setlocal enabledelayedexpansion

echo Compiling AuraOS Kiosk System...

set files=

for /R %%f in (*.cpp) do (
    set files=!files! "%%f"
)

g++ !files! -o kiosk.exe

if %errorlevel% neq 0 (
    echo Build Failed!
) else (
    echo Build Successful!
)

pause