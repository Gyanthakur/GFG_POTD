#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;
}

int maxSweetness(vector<int> &sweetness, int N, int K)
{
    // Write your code here.
    int left = 1;                                                  // Minimum possible sweetness of a piece
    int right = accumulate(sweetness.begin(), sweetness.end(), 0); // Maximum possible sweetness of a piece

    while (left < right)
    {
        int mid = (left + right + 1) / 2; // Midpoint of the sweetness range
        int pieces = 0;                   // Number of pieces that can be formed with the current sweetness
        int currentSweetness = 0;         // Sweetness of the current piece being formed

        for (int s : sweetness)
        {
            currentSweetness += s;
            if (currentSweetness >= mid)
            {
                pieces++;
                currentSweetness = 0;
            }
        }

        if (pieces > K)
        {
            // If we can form more pieces than allowed, sweetness should be increased
            left = mid;
        }
        else
        {
            // If we can form fewer pieces than allowed, sweetness should be decreased
            right = mid - 1;
        }
    }

    return left;
}