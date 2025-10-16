#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

class Solution
{
public:
    int Count(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 1)
                {
                    int cnt = 0;
                    for (int l = -1; l <= 1; l++)
                    {
                        for (int r = -1; r <= 1; r++)
                        {
                            int row = i + l;
                            int col = j + r;
                            // if(row==i and col==j) continue;
                            if (row >= n or col >= m or row < 0 or col < 0)
                                continue;
                            if (mat[row][col] == 0)
                                cnt++;
                        }
                    }
                    if (cnt % 2 == 0 and cnt != 0)
                        ans++;
                }
                // else continue;
            }
        }
        return ans;
    }
};