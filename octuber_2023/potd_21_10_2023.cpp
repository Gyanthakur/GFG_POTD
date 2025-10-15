class Solution
{
public:
    long long sumOfDivisors(int n)
    {
        // Write Your Code here
        long long sum = 0;
        for (int i = 1; i <= n; i++)
        {
            sum += i * (n / i);
        }
        return sum;
    }
};