@echo off
SETLOCAL

set /p "commit_message=Enter your commit message: "

git add -A

git commit -m %commit_message%

git push

git status

pause

ENDLOCAL