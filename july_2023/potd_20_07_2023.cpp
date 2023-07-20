#include<bits/stdc++.h>
using namespace std;
int main(){

return 0;
}

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
     char nonrepeatingCharacter(string S)
    {
       //Your code here
       vector<int>v(26,0);
       int n=S.length();
       for(int i=0;i<n;i++)
       {
           v[S[i]-'a']++;
       }
       for(int i=0;i<n;i++)
       {
           if(v[S[i]-'a']==1)
           return S[i];
       }
       return '$';
       
    }
    

};