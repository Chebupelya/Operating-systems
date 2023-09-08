chcp 65001
echo off
cls

echo --параметр 1: %1
echo --параметр 2: %2
echo --параметр 3: %3
set /A res = %1 %3 %2
echo %res%
pause