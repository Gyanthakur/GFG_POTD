class Solution {
private:
    bool split(int *arr,int size,int sum,int k)
    {
        int s=0;
        int count=0;
        for(int i=0;i<size;i++)
        {
            if(s+arr[i]<=sum) s=s+arr[i];
            else
            {
                count++;
                if(count>=k || arr[i]>sum) return false;
                s=arr[i];
            }
        }
        return true;
    }
    public:
    int splitArray(int arr[] ,int N, int K) {
        int sum=0;

        for(int i=0;i<N;i++) sum+=arr[i];
        int s=1;
        int e=sum;
        int mid;
        int ans=INT_MAX;
        while(s<=e)
        {
            mid=s+(e-s)/2;
            if(split(arr,N,mid,K))
            {

                ans=min(ans,mid);
                e=mid-1;
            }
            else s=mid+1;
        }
        return ans;
    }
};
