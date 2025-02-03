SETLOCAL


@echo  off
echo ====================== git status ============================
git status
pause

echo/
set /p "commit_message=Enter your commit message: "

echo ====================== git add -A ============================
git add -A
echo/
echo ====================== git commit -m "My Message" ============
git commit -m %commit_message%
echo/
echo ====================== git push ==============================
git push
echo/
echo ====================== git status ============================
git status
echo/


ENDLOCAL