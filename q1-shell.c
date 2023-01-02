#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void shellSort(long[], long);
clock_t start, end;
double cpu_time_used;
int tot_comp, tot_step;

int main()
{
    int num = 1, n = 5000, swaptimes = 0;
    long array[30000];

    for (int i = 1; i <= 6; i++)
    {
        srand(time(0));
        tot_comp = 0, tot_step = 0;
        for (int j = 0; j < n; j++)
        {
            array[j] = rand() % n;
        }
        start = clock();
        shellSort(array, n);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("\nSECTION : %d", i);
        printf("\nSIZE : %d", n);
        printf("\nTIME: %.4f seconds", cpu_time_used);
        printf("\nTOTAL COMPARE: %d", tot_comp);
        printf("\nTOTAL SWAP: %d", tot_step);
        printf("\n============================");
        n += 5000;
    }
    return 0;
}

void shellSort(long array[], long n)
{
    for (int interval = n / 2; interval > 0; interval /= 2)
    {
        tot_comp++;
        for (int i = interval; i < n; i += 1)
        {
            int temp = array[i];
            int j;
            for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
            {
                tot_comp++;
                array[j] = array[j - interval];
            }
            array[j] = temp;
            tot_step++;
            tot_comp++;
        }
    }
}