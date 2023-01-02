#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void heap_sort(long[], long);
void display(long[], long);
clock_t start, end;
double cpu_time_used;
int tot_comp, tot_step;
void heapify(long[], int, int);

void main()
{
    int num = 1, n = 5000;
    long array[30000];

    for (int i = 1; i <= 6; i++)
    {
        srand(time(0));
        tot_comp = 0, tot_step = 0;
        for (int j = 0; j < n; j++)
            array[j] = rand() % n;

        start = clock();
        heap_sort(array, n);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("\n\nSECTION : %d", i);
        printf("\nSIZE : %d", n);
        printf("\nTIME: %.4f seconds", cpu_time_used);
        printf("\nTOTAL COMPARE: %d", tot_comp);
        printf("\nTOTAL STEP: %d", tot_step);
        printf("\n============================");
        n += 5000;
    }
}

void swap(long *a, long *b)
{
    long temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(long arr[], int N, int i)
{

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    tot_comp++;
    if (left < N && arr[left] > arr[largest])
    {
        largest = left;
    }

    tot_comp++;
    if (right < N && arr[right] > arr[largest])
    {
        largest = right;
    }

    tot_comp++;
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        tot_step++;
        heapify(arr, N, largest);
    }
}

void heap_sort(long arr[], long N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    for (int i = N - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        tot_step++;
        heapify(arr, i, 0);
    }
}