#include<bits/stdc++.h>
using namespace std;
/*

1. Group the adjacent elements based on their nature -> even or odd.
2. Keep traversing ahead if the nature of current index is same as next index.
3. If the nature of next index is different, then 
   1. sort the array from start index to current index
   2. reverse the array from start index to current index
   3. update start index to current index
4. repeat the steps 2. and 3.
5. return the final array.

*/



class Solution
{
    public:
        vector <int> lexicographicallyLargest(vector <int> &a,int n)
        {
            int i=0;
            while(i<n)
            {
                int j=i+1;
                while(j<n && a[j]%2==a[j-1]%2)
                j++;
                sort(a.begin()+i,a.begin()+j,greater<int>());
                i=j;
            }
            return a;
        }
};