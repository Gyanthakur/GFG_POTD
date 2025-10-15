#include <bits/stdc++.h>
using namespace std;

int main()
{
    return 0;

    class Solution
    {
    public:
        int maxIndexDiff(int arr[], int n)
        {
            // code here
            int nums[n];
            for (int i = 0; i < n; i++)
            {
                nums[i] = arr[i];
            }
            sort(nums, nums + n);
            int k = n - 1;
            int ans = 0;
            int i = 0;
            int j = n - 1;
            while (i < j)
            {
                int diff = j - i;
                if (arr[i] <= arr[j])
                {
                    ans = max(ans, diff);
                    i++;
                    j = n - 1;
                }
                else if (arr[i] == nums[k])
                {
                    k--;
                    i++;
                }
                else
                {
                    j--;
                }
            }
            return ans;
        }
    };
}