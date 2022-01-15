#include <iostream>
using namespace std;

int binary(int n, int *arr)
{
    if (n == 0)
        return 1;
    if (n == 1)
    {
        arr[0] = 1;
        return 1;
    }
    int pow = 1;
    int count = 0;
    while (pow <= n)
    {
        pow = pow * 2;
        count++;
    }
    pow /= 2;
    count--;
    int rem = n % pow;
    arr[count] = 1;
    binary(rem, arr);
    return count + 1;
}

void reverse(int *arr,int n){
    for(int i=0; i<n/2; i++){
        int temp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = temp;
    }
}
int main()
{
    //converting anumber into binary
    int arr[1000];
    for (int i = 0; i < 100; i++)
        arr[i] = 0;
    int size = binary(1000000000, arr);
    reverse(arr,size);
    for(int i=0; i<size; i++)
    cout<<arr[i];
    cout<<endl;
   
}