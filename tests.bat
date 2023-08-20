@echo off
call build.bat
.\bazel-bin\tests_runner.exe -s
