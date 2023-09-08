
chcp 65001
@echo off
cls


echo -- строка параметров: %*
echo -- режим: %1
echo -- имя файла: %2

if "%1" equ "" (
    echo ---+  %~n0 режим файла
    echo ---++  режим = {создать, удалить}
    echo ---++  файл  = имя файла
) else (
    if "%1" equ "удалить" (
        if "%2" equ "" (
            echo ---+ не задано имя файла
        ) else (
            if not exist "%2" (
                echo ---+ файл %2 не найден
            ) else (
                del "%2"
                echo ---+ файл %2 удалён
            )
        )
    ) else if "%1" equ "создать" (
        if "%2" equ "" (
            echo ---+ не задано имя файла
        ) else (
            if exist "%2" (
                echo ---+ файл %2 уже есть
            ) else (
                copy NUL %2 >NUL
                echo ---+ файл %2 создан
            )
        )
    ) else (
        echo ---+ режим задан не корректно
    )
)

pause