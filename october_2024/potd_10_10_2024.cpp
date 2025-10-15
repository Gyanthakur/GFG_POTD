//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution
{
public:
    int maxDistance(vector<int> &arr)
    {
        unordered_map<int, int> firstOccurrence; // stores the first occurrence index of elements
        int maxD = -1;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            if (firstOccurrence.find(arr[i]) != firstOccurrence.end())
            {
                // if the element is already in the map, calculate the distance
                int temp = i - firstOccurrence[arr[i]];
                maxD = max(maxD, temp);
            }
            else
            {
                // store the first occurrence of the element
                firstOccurrence[arr[i]] = i;
            }
        }

        return maxD;
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
        vector<int> arr;
        string input;
        getline(cin, input);

        stringstream s1(input);
        int num;
        while (s1 >> num)
        {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxDistance(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends