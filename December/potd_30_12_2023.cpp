#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <set>

using namespace std;
#define int long long
long long t;

int isPossible(int N, int coins[])
{
    int totalSum = 0;

    for (int i = 0; i < N; i++)
    {
        totalSum += coins[i];
    }

    if (totalSum == 2024 || totalSum % 20 == 0 || totalSum % 24 == 0)
    {
        return 1;
    }

    bitset<2025> possibleSums;
    possibleSums[0] = 1;

    for (int i = 0; i < N; i++)
    {
        for (int j = 2024; j >= coins[i]; j--)
        {
            if (possibleSums[j - coins[i]])
            {
                possibleSums[j] = 1;

                if (j == 2024 || j % 20 == 0 || j % 24 == 0)
                {
                    return 1;
                }
            }
        }
    }

    return 0;
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