chcp 65001
echo off
cls

echo --строка параметров: %*
echo --параметр 1: %1
echo --параметр 2: %2
echo --параметр 3: %3
set /A first = %1
set /A second = %2
set /A third = %3
set /A sum = first + second
set /A composition = first * second
set /A del = third / second
set /A min = second - third
set /A mn1 = second - third
set /A mn2 = first - second
set /A composition2 = mn1 * mn2
echo %first% + %second% = %sum%
echo %first% * %second% = %composition%
echo %third% / %second% = %del%
echo %second% - %third% = %min%
echo (%second% - %third%) * (%first% - %second%) = %composition2%
pause