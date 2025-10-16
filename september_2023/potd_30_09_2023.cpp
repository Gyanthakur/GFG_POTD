#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <set>

using namespace std;
#define int long long
long long t;

class Solution
{
public:
    // Function to modify the matrix such that if a matrix cell matrix[i][j]
    // is 1 then all the cells in its ith row and jth column will become 1.
    void booleanMatrix(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> r(n), c(m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                if (matrix[i][j])
                {
                    r[i] = 1;
                    c[j] = 1;
                }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (r[i] || c[j])
                    matrix[i][j] = 1;
            }
        }
    }
};

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