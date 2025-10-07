@echo off
setlocal enabledelayedexpansion

echo 正在搜索并执行所有 keilkill.bat 文件...

REM 遍历当前目录及子目录下的所有 keilkill.bat 文件
for /r %%f in (keilkill.bat) do (
    echo.
    echo 执行：%%f
    call "%%f"
)

echo.
echo 所有 keilkill.bat 执行完毕。
pause
