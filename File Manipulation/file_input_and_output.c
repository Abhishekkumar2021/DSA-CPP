#include <stdio.h>
int main(int argc,char**argv)
{
    FILE *from = fopen(argv[1], "r");
    long int wc=0,lc=0,cc=0;
    int x;
    while ((x = fgetc(from)) != EOF)
    {
        cc++;
        if(x=='\n')
            lc++;
        if(x==' ' || x==',' || x=='.' || x=='\n')
            wc++;
    }
    fclose(from);
    printf("The number of words = %ld\n", wc);
    printf("The number of lines = %ld\n", lc);
    printf("The number of characters = %ld\n",cc);
    return 0;
}
