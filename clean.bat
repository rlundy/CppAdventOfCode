@echo off
bazel clean --expunge
exit /b %ERRORLEVEL%
