//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long get(string &s,int k)
    {
         // unordered_map<char,int> a;
    vector<int> a(26,0);
         
      int i=0;
      int j=0;
   // a[s[0]]++;
   a[s[0]-'a']++;
   int distinct=1;
    long long sum=0;
      for(;j<s.size();)
      {
         if(distinct<=k)
         {
             sum+=j-i+1;
               j++;
             
               if(j<s.size()&&a[s[j]-'a']==0)
               {
                   distinct++;
               }
               if(j<s.size())
               a[s[j]-'a']++;
         }
         else
         {
             a[s[i]-'a']--;
            if(a[s[i]-'a']==0)
            {
                distinct--;
            }
         
             i++;
             
         }
         
       
      }
      return sum;
    }
  
    long long int substrCount (string s, int k) {
      long long a= get(s,k);
      long long  b=get(s,k-1);
      return a-b;
    	//code here.
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends
