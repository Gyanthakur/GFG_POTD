#include <bits/stdc++.h>
using namespace std;

int findMinOperation(int n, int matrix[][10])
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum += matrix[i][j];
        }
    }
    int rs = 0;
    int cs = 0;
    for (int i = 0; i < n; i++)
    {
        int ros = 0;
        for (int j = 0; j < n; j++)
        {
            ros += matrix[i][j];
            rs = max(rs, ros);
        }
        int cos = 0;
        for (int j = 0; j < n; j++)
        {
            cos += matrix[j][i];
            cs = max(rs, cos);
        }
        int maxSum = max(cs, rs);
        int ans = maxSum * n - sum;
        return ans;
    }
}

int main()
{
    int n;
    cin >> n;
    int matrix[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout << findMinOperation(n, matrix);
    return 0;
}