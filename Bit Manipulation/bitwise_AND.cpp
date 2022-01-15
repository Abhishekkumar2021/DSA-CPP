#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
//we can use bitwise and to check whether the given number is even or odd. i.e when i = 1;
    for (int i = 0; i < 256; i++)
    {
        printf("for i = %d\n", i);
        for (int j = 0; j < 256; j++)
        {
            printf("%d ", (i & j));
        }
        printf("\n");
    }
}