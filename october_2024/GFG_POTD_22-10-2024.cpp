class Solution {
  public:
    int sameOccurrence(vector<int>& arr, int x, int y) {
        // code here
        unordered_map<int, int> value;
        int countX = 0, countY =0;
        int ans = 0;
        value[0] = 1;
        for(auto c : arr){
            if(c == x)
                countX++;
            if(c == y)
                countY++;
                
            int diff = countX- countY;
            ans += (value[diff]);
            value[diff]++;
        }
        return ans;
    }
};
