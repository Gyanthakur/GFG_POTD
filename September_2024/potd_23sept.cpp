//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> findTwoElement(vector<int> &arr)
    {
        // code here
        long long n = arr.size();

        long long s = (n * (n + 1)) / 2;
        long long ssq = (n * (n + 1) * (2 * n + 1)) / 6;

        long long missing = 0, repeating = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            s -= 1LL * arr[i];
            ssq -= 1LL * arr[i] * arr[i];
        }

        missing = (s + ssq / s) / 2;
        repeating = missing - s;

        return {(int)repeating, (int)missing};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string input;
        int num;
        vector<int> arr;
        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num)
        {
            arr.push_back(num);
        }
        Solution ob;
        auto ans = ob.findTwoElement(arr);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends