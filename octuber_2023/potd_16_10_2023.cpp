class Solution
{
public:
    int largestIsland(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int ax[] = {0, 0, 1, -1};
        int ay[] = {1, -1, 0, 0};
        
        
        auto isVal = [&](int x, int y) -> bool {
             if(x < 0 || y < 0 || x == n || y == n) return false;
             return true;
        };
        
        int cur = 100;
        
        function<int(int,int)> dfs = [&](int x, int y) {
            if(!isVal(x, y) || grid[x][y] != 1) return 0;
            grid[x][y] = cur;
            int ans = 0;
            for(int i=0; i<4; i++){
                ans += dfs(x + ax[i], y + ay[i]);            
            }
            return ans + 1;
        };
        int ans = -1;
        unordered_map<int, int> map;
        for(int i=0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1){
                    map[cur] = dfs(i, j);
                    ans = max(ans, map[cur]);
                    cur++;
                }
            }
        }
        
        
        for(int i=0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 0){
                    unordered_set<int> st;
                    
                    for(int k = 0; k < 4; k++){
                        int x = i + ax[k];
                        int y = j + ay[k];
                        if(isVal(x, y))
                            st.insert(grid[i + ax[k]][j + ay[k]]);
                    }
                    int temp = 1;
                    for(int x : st){
                        temp += map[x];
                    }
                    ans = max(ans, temp);
                }
            }
        }
        
        return ans;
    }
};