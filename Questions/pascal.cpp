vector<vector<int>> generate(int n)
{
    vector<vector<int>> arr(n);
    //  **arr= new int*[n];
    for (int i = 0; i < n; i++)
    {

        arr[i].resize(i + 1);
    }

    if (n == 1)
    {
        arr[0][0] = 1;
    }
    else if (n == 2)
    {
        arr[0][0] = 1, arr[1][0] = 1, arr[1][1] = 1;
    }
    else
    {

        for (int i = 2; i < n; i++)
        {

            int p = 1, q = i - 1;
            arr[0][0] = 1;
            arr[1][0] = 1;
            arr[1][1] = 1;
            arr[i][0] = 1;
            arr[i][i] = 1;
            while (p <= q)
            {

                arr[i][p] = arr[i - 1][p] + arr[i - 1][p - 1];
                p++;
            }
        }
    }

    return arr;
}