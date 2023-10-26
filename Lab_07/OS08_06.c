#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

int main() {
    struct timeval start_time, end_time;
    int iteration = 0;

    // Получаем начальное время
    gettimeofday(&start_time, NULL);

    while (1) {
        iteration++;
        // Получаем текущее время
        gettimeofday(&end_time, NULL);

        // Рассчитываем разницу во времени
        double elapsed_time = (end_time.tv_sec - start_time.tv_sec) + 
                             (end_time.tv_usec - start_time.tv_usec) / 1000000.0;

        // Выводим счетчик итераций и затраченное время
        printf("Итерация: %d, Время: %.2f сек.\n", iteration, elapsed_time);

        // Если прошло 2 секунды процессорного времени, завершаем цикл
        if (elapsed_time >= 2.0) {
            break;
        }
    }

    return 0;
}
