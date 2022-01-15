#include <bits/stdc++.h>
using namespace std;
class YoungTableau
{
    int **matrix;
    int n;
    int m;

public:
    YoungTableau()
    {
        matrix = NULL;
        n = 0;
        m = 0;
    }
    YoungTableau(int n, int m)
    {
        this->n = n;
        this->m = m;
        matrix = new int *[n];
        for (int i = 0; i < n; i++)
        {
            matrix[i] = new int[m];
            for (int j = 0; j < m; j++)
            {
                matrix[i][j] = INT_MAX;
            }
        }
    }
    YoungTableau(int size)
    {
        float x = sqrt(size);
        int intPart = x;
        if (n == intPart)
        {
            this->m = x;
            this->n = x;
        }
        else
        {
            this->n = intPart + 1;
            this->m = intPart;
        }
        matrix = new int *[n];
        for (int i = 0; i < n; i++)
        {
            matrix[i] = new int[m];
            for (int j = 0; j < m; j++)
            {
                matrix[i][j] = INT_MAX;
            }
        }
    }
    YoungTableau(int arr[], int size)
    {
        float x = sqrt(size);
        int intPart = x;
        if (x == intPart)
        {
            this->m = x;
            this->n = x;
        }
        else
        {
            this->n = intPart + 1;
            this->m = intPart;
        }
        matrix = new int *[n];
        for (int i = 0; i < n; i++)
            matrix[i] = new int[m];
        int row = -1;
        int col = 0;
        for (int i = 0; i < m * n; i++)
        {

            if (i % m == 0)
            {
                row++;
                col = 0;
            }
            if (i < size)
                matrix[row][col] = arr[i];
            else
                matrix[row][col] = INT_MAX;
            col++;
        }
    }
    ~YoungTableau()
    {
        for (int i = 0; i < n; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
    void print()
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

int main()
{
    int arr[] = {9, 16, 3, 2, 4, 8, 5, 14, 12};
    YoungTableau yt(arr, 9);
    yt.print();
}