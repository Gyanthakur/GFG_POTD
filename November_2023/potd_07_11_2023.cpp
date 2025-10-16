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
    // Function to return sum of upper and lower triangles of a matrix.
    vector<int> sumTriangles(const vector<vector<int>> &matrix, int n)
    {
        int sumy = 0;
        int lowe = 0;
        for (int i = 0; i < n; i++)
        {
            sumy += accumulate(matrix[i].begin() + i, matrix[i].end(), 0);
            lowe += accumulate(matrix[i].begin(), matrix[i].begin() + i + 1, 0);
        }
        return {sumy, lowe};
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