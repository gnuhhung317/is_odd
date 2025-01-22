@echo off
start main.exe
if %ERRORLEVEL% neq 0 (
    echo "main.exe failed to start"
    exit /b %ERRORLEVEL%
)

git add .
if %ERRORLEVEL% neq 0 (
    echo "git add failed"
    exit /b %ERRORLEVEL%
)

git commit -m "Update green graph"
if %ERRORLEVEL% neq 0 (
    echo "git commit failed"
    exit /b %ERRORLEVEL%
)

git push origin main
if %ERRORLEVEL% neq 0 (
    echo "git push failed"
    exit /b %ERRORLEVEL%
)

echo "All commands executed successfully!"
