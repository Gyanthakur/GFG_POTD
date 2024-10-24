class Solution{
    public:
    vector<int>modifyAndRearrangeArray(vector<int> &arr){
        //Complete the function
        int j=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]) arr[j++]=(i<arr.size()-1 && arr[i]==arr[i+1])?arr[i++]*2:arr[i];
        }
        fill(arr.begin()+j,arr.end(),0);
        return arr;
    }
};
