#include <bits/stdc++.h>
using namespace std;
// let's first solve a problem.
// given an string you have to find the maximum occuring letter
char maxOccurence(string str)
{
    int arr[256]; // frequency array
    for (int i = 0; i < 256; i++)
        arr[i] = 0;
    for (int i = 0; i < str.size(); i++)
    {
        int index = str[i];
        arr[index]++;
    }
    int maxIndex = 0;
    for (int i = 0; i < 256; i++)
    {
        if (arr[i] > arr[maxIndex])
            maxIndex = i;
    }
    char ans = maxIndex;
    return ans;
}
int main()
{
    string input;
    cout << "Enter a string of characters : ";
    getline(cin, input);
    cout << "Maximum occuring word is : " << maxOccurence(input) << endl;
}