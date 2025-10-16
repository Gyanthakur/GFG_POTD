class Solution
{
public:
    int isPossible(int n, int arr[])
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            arr[i] %= 3;
            sum += arr[i];
        }
        return sum % 3 == 0;
    }
};