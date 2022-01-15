#include <stdio.h>
#include <stdlib.h>
void pattern(int **arr, int size, int index, int value)
{
    if (value <= 0)
        return;
    for (int i = index; i < size - index; i++)
    {
        for (int j = index; j < size - index; j++)
        {
            if (i == index || j == index || i == size - index - 1 || j == size - 1 - index)
                arr[i][j] = value;
        }
    }
    pattern(arr, size, index + 1, value - 1);
}

int main()
{
    int value, **A;
    scanf("%d", &value);
    A = (int **)malloc((2 * value - 1) * sizeof(int *));
    for (int i = 0; i < (2 * value - 1); i++)
        A[i] = (int *)malloc((2 * value - 1) * sizeof(int));
    pattern(A, 2 * value - 1, 0, value);
    for (int i = 0; i < (2 * value - 1); i++)
    {
        for (int j = 0; j < (2 * value - 1); j++)
            printf("%2d ", A[i][j]);
        printf("\n");
    }
}