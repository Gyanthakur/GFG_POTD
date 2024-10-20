
/* Given two sorted arrays of distinct integers arr1 and arr2. Each array may have some elements in common with the other array. Find the maximum sum of a path from the beginning of any array to the end of any array. You can switch from one array to another array only at the common elements.

Note:  When we switch from one array to other,  we need to consider the common element only once in the result.
*/
/*
Input: arr1 = [2, 3, 7, 10, 12] , arr2 = [1, 5, 7, 8]
Output: 35
Explanation: The path will be 1+5+7+10+12 = 35 
where 1 and 5 come from arr2 and then 7 is common so we switch to arr1 and add 10 and 12.
*/

// solution

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
        // Code here
        int n=arr1.size() , m=arr2.size() ;
        int i=0,j=0,sum1=0,sum2=0 ;
        arr1.push_back(INT_MAX);
        arr2.push_back(INT_MAX);
        while( (i<n || j<m) )
        {
            if( arr1[i] < arr2[j] )
            {
                sum1+=arr1[i];
                i++;
            }
            else if( arr1[i] > arr2[j] )
            {
                sum2+= arr2[j];
                j++;
            }
            else
            {
                sum1=max(sum1,sum2)+arr1[i];
                sum2=sum1;
                i++,j++;
            }
        }
        return max( sum1 , sum2 );
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr1;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }
        vector<int> arr2;
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            arr2.push_back(number2);
        }
        Solution ob;
        long long ans = ob.maxPathSum(arr1, arr2);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends