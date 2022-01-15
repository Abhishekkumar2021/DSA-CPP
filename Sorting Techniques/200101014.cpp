#include<iostream>
using namespace std;
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int temp = arr[i], minindex = i;
        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[minindex])
                minindex = j;
        }
        arr[i] = arr[minindex];
        arr[minindex] = temp;
    }
}
int sumOfDigits(int x)
{
    int sum = 0;
    while (x > 0)
    {
        int digit = x % 10;
        sum += digit;
        x /= 10;
    }
    return sum;
}
int main(){
    int numOfElements;
    cin >> numOfElements;
    int arr[numOfElements];
    for (int i = 0; i < numOfElements; i++)
    {
        cin >> arr[i];
    }
    selectionSort(arr, numOfElements);
    int range = 0;
    for(int i=0; i<numOfElements; i++){
        if(range<sumOfDigits(arr[i]))
        range = sumOfDigits(arr[i]);
    }

    int countingArray[range+1];
    for(int i=0; i<range+1; i++){
        countingArray[i]=0;
    }
    for(int i=0; i<numOfElements; i++){
        int sum = sumOfDigits(arr[i]);
        countingArray[sum]++;
    }
    for(int i=1; i<=range; i++){
        countingArray[i]+=countingArray[i-1];
    }
    int final[numOfElements];
    for(int i=numOfElements-1; i>=0; i--){
        int sum = sumOfDigits(arr[i]);
        int index = countingArray[sum];
        final[index-1] = arr[i];
        countingArray[sum]--;
    }
    for(int i=0; i<numOfElements; i++){
        cout<<final[i]<<" ";
    }
    cout<<"\n";

}