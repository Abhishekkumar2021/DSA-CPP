#include <stdio.h>
#include <stdlib.h>

struct ker
{
    int row;
    int col;
    int value;
};

struct image
{
    int row;
    int col;
    int value;
};

struct conv_image
{
    int row;
    int col;
    int value;
};

int main()
{
    FILE *inptr = fopen("week15-ML1-input.txt", "r");
    FILE *outptr = fopen("output.txt", "w");
    if (inptr == NULL)
        fputs("Input File doesn't opened or doesn't exist.\n", outptr);
    else
    {
        int krow, kcol, ksize;
        fscanf(inptr, "%d%d%d", &krow, &kcol, &ksize);
        struct ker *K;
        K = (struct ker *)malloc(ksize * sizeof(struct ker));
        for (int i = 0; i < ksize; i++)
        {
            fscanf(inptr, "%d%d%d", &(K[i].row), &(K[i].col), &(K[i].value));
        }

        int irow, icol, isize;
        fscanf(inptr, "%d%d%d", &irow, &icol, &isize);
        struct image *I;
        I = (struct image *)malloc(isize * sizeof(struct image));
        for (int i = 0; i < isize; i++)
        {
            fscanf(inptr, "%d%d%d", &(I[i].row), &(I[i].col), &(I[i].value));
        }
        fputs("Hello friends!", outptr);
        printf("%d", K[0].value);
        struct conv_image *CI;
        CI = (struct conv_image *)malloc(isize * sizeof(struct conv_image));
        // for (int i = 0; i < irow; i++)
        // {
        //     for (int j = 0; j < icol; i++)
        //     {
        //     }
        // }
        free(K);
        free(I);
        free(CI);
    }
    fclose(inptr);
    fclose(outptr);
}