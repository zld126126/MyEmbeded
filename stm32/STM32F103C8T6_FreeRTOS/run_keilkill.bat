@echo off
setlocal enabledelayedexpansion

echo ����������ִ������ keilkill.bat �ļ�...

REM ������ǰĿ¼����Ŀ¼�µ����� keilkill.bat �ļ�
for /r %%f in (keilkill.bat) do (
    echo.
    echo ִ�У�%%f
    call "%%f"
)

echo.
echo ���� keilkill.bat ִ����ϡ�
pause
