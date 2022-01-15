#include <bits/stdc++.h>
using namespace std;
double determinant(double **matrices, int size)
{
    if (size == 2)
    {
        return (matrices[0][0] * matrices[1][1] - matrices[1][0] * matrices[0][1]);
    }
    double ***childMatrices = new double **[size];
    for (int i = 0; i < size; i++)
    {
        childMatrices[i] = new double *[size - 1];
        for (int j = 0; j < size - 1; j++)
        {
            childMatrices[i][j] = new double[size - 1];
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 1, r = 0; j < size; j++, r++)
        {
            for (int k = 0, c = 0; k < size; k++, c++)
            {
                if (k == i)
                {
                    k++;
                }
                childMatrices[i][r][c] = matrices[j][k];
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            for (int k = 0; k < size - 1; k++)
                cout << childMatrices[i][j][k] << " ";
            cout << endl;
        }
        cout << "\n\n";
    }

    double ans[size];
    for (int i = 0; i < size; i++)
    {
        ans[i] = determinant(childMatrices[i], size - 1);
    }
    double finalAnswer = 0;
    for (int i = 0; i < size; i++)
    {
        finalAnswer += pow(-1, i) * ans[i];
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            delete[] childMatrices[i][j];
        }
        delete[] childMatrices[i];
    }
    delete[] childMatrices;

    return finalAnswer;
}

int main()
{
    double **matrix;
    int n;
    cin >> n;
    matrix = new double *[n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new double[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }
    cout << determinant(matrix, n) << endl;
}