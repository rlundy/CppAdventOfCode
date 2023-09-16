@echo off
call build.bat
if ERRORLEVEL 1 (
    exit /b 1
)
.\bazel-bin\tests_runner.exe %1 %2 %3 %4 %5 %6 %7 %8 %9
exit /b %ERRORLEVEL%
