#include <stdio.h>
#include <time.h>

int main() {
    // Получаем текущее время
    time_t currentTime;
    struct tm *localTimeInfo;
    time(&currentTime);
    localTimeInfo = localtime(&currentTime);

    // Форматируем и выводим дату и время
    printf("%02d.%02d.%04d %02d:%02d:%02d\n",
           localTimeInfo->tm_mday, localTimeInfo->tm_mon + 1, localTimeInfo->tm_year + 1900,
           localTimeInfo->tm_hour, localTimeInfo->tm_min, localTimeInfo->tm_sec);

    return 0;
}
