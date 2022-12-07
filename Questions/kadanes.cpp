#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {-2, 4, 0, 3, -5}, i, j, n = 5, max1 = 0, max2=0;

    for (i = 0; i < n; i++)
    {        
        for (j = i; j < n; j++)
        {
            max1 = max1 + arr[j];
            if (max2 < max1)
            {
                max2 = max1;
            }
        }
    }
    cout<<max2;
}