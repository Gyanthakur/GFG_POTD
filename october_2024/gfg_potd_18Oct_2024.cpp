/*
        Given an array arr[] of positive integers where every element appears even times except for one.
        Find that number occurring an odd number of times.

Examples:

Input: arr[] = [1, 1, 2, 2, 2]
Output: 2
Explanation: In the given array all element appear two times except 2 which appears thrice.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    int getSingle(vector<int> &arr)
    {
        // we will use xor operator to solve this problem efficiently.
        //  as, x^0=x. and x^x=0
        // start to iterate over the array, & at last
        // we will get our required answer.
        int a = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            a = a ^ arr[i];
        }
        return a;
    }
};

//{ Driver Code Starts.

int main()
{
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--)
    {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.getSingle(arr);
        cout << res << endl;
    }
    return 0;
}
// } Driver Code Ends