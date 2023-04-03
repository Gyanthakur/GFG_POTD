#include<bits/stdc++.h>
using namespace std;




class Solution{
    public:
    
    Shop shop;
    Solution(Shop s)
    {
        this->shop = s;
    }
    long long find(int n, long k){
        // Return the number of chocolates Geek had
        // enjoyed out of 'n' chocolates availabe in the
        // 'shop'.
        long long ans=0;
        long long l=0;
        long long r=n-1;
        while(r>=0 && k>=0)
        {
            l=0;
            long long index=-1;
            long long index_val;
            while(l<=r)
            {
                long long mid = (l+r)/2;
                long long mid_price = shop.get(mid);
                if(mid_price<=k)
                {
                    index=mid;
                    index_val=mid_price;
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }
            }
            ans += (k/index_val);
            k=k%(index_val);
            r=index-1;
            
        }
        return ans;
    }

};