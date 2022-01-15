#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> multiply(vector<vector<int>> A, vector<vector<int>> B)
{
    int rowA = A.size();
    int rowB = B.size();
    int colA = A[0].size();
    int colB = B[0].size();
    if (colA != rowB) // column of A and rows of B must be same
        return {};

    vector<vector<int>> result(rowA);
    for (int i = 0; i < rowA; ++i)
    {
        for (int j = 0; j < colB; ++j)
        {
            int result_ij = 0;
            for (int k = 0; k < colA; ++k)
            {
                result_ij += A[i][k] * B[k][j];
            }
            result[i].push_back(result_ij);
        }
    }
    return result;
} // time complexity = theta(pqr), where p = rowA, q = common one(colA OR rowB), r = colB
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int rowsA;
    int colA;
    cin >> rowsA;
    cin >> colA;
    vector<vector<int>> matrixA(rowsA);
    for (int i = 0; i < rowsA; i++)
    {

        for (int j = 0; j < colA; j++)
        {
            int x;
            cin >> x;
            matrixA[i].push_back(x);
        }
    }
    int rowsB;
    int colB;
    cin >> rowsB;
    cin >> colB;
    vector<vector<int>> matrixB(rowsB);
    for (int i = 0; i < rowsB; i++)
    {

        for (int j = 0; j < colB; j++)
        {
            int x;
            cin >> x;
            matrixB[i].push_back(x);
        }
    }
    vector<vector<int>> result = multiply(matrixA, matrixB);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}