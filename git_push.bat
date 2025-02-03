SETLOCAL


git status
echo Please enter to continue .......
pause

set /p "commit_message=Enter your commit message: "

git add -A
git commit -m %commit_message%
git push
git status


ENDLOCAL