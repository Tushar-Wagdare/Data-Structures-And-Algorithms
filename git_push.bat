SETLOCAL


@echo  off
echo ====================== git status ============================
git status
pause

set /p "commit_message=Enter your commit message: "

echo ====================== git add -A ============================
git add -A
echo ====================== git commit -m %commit_message% ========
git commit -m %commit_message%
echo ====================== git push ==============================
git push
echo ====================== git status ============================
git status


ENDLOCAL