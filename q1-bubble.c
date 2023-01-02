#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void bubble_sort(long[], long);
clock_t start, end;
double cpu_time_used;
int tot_comp, tot_step;
void swap(long *, long *);

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
        bubble_sort(array, n);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("\nSECTION : %d", i);
        printf("\nSIZE : %d", n);
        printf("\nTIME: %.2f seconds", cpu_time_used);
        printf("\nTOTAL COMPARE: %d", tot_comp);
        printf("\nTOTAL SWAP: %d", tot_step);
        printf("\n============================");
        n += 5000;
    }
    return 0;
}

void bubble_sort(long list[], long n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            tot_comp++;
            if (list[j] > list[j + 1])
            {
                swap(&list[j], &list[j + 1]);
                tot_step++;
            }
        }
    }
}

void swap(long *xp, long *yp)
{
    long temp = *xp;
    xp = yp;
    *yp = temp;
}