#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <set>

using namespace std;
#define int long long
long long t;

int determinantOfMatrix(vector<vector<int>> matrix, int n)
{

    // if the matrix is 1 * 1, return the single element
    if (n == 1)
    {
        return matrix[0][0];
    }

    int determinant = 0;

    // iterate over each element in the first row of the matrix
    for (int i = 0; i < n; i++)
    {
        vector<vector<int>> InnerMatrix(n - 1, vector<int>(n - 1));

        // create a submatrix excluding the current row and column
        for (int j = 1; j < n; j++)
        {
            int col = 0;
            for (int k = 0; k < n; k++)
            {
                if (k == i)
                {
                    continue;
                }
                InnerMatrix[j - 1][col++] = matrix[j][k];
            }
        }

        // calculate the determinant using the formula
        if (i % 2 == 0)
        {
            determinant += (matrix[0][i]) * (determinantOfMatrix(InnerMatrix, n - 1));
        }
        else
        {
            determinant -= (matrix[0][i]) * (determinantOfMatrix(InnerMatrix, n - 1));
        }
    }
    // return the calculated determinant
    return determinant;
}

void solution()
{
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    while (t--)
    {
        solution();
        cout << endl;
    }
    return 0;
}