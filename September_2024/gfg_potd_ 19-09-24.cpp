// Reverse Words

/*Given a String str, reverse the string without reversing its individual words. Words are separated by dots.*/
/*
    Input: str = i.like.this.program.very.much
    Output: much.very.program.this.like.i
    Explanation: After reversing the whole string(not individual words), the input string becomes much.very.program.this.like.i
*/

// solution

//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to reverse words in a given string.
    string reverseWords(string str)
    {
        // code here
        int j = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '.')
            {
                reverse(str.begin() + j, str.begin() + i);
                j = i + 1;
            }
            else if (i == str.length() - 1)
                reverse(str.begin() + j, str.end());
        }
        reverse(str.begin(), str.end());
        return str;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends