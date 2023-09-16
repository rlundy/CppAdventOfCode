@echo off
call build.bat
if ERRORLEVEL 1 (
    exit /b 1
)
.\bazel-bin\tests_runner.exe
exit /b %ERRORLEVEL%
