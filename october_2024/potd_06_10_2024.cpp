/*
GFG POTD 6 Oct 2024

Problem Descrption:

Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) 
consisting of '0's (Water) and '1's(Land). Find the number of islands.

Note: An island is either surrounded by water or the boundary of a grid and is formed by 
connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

Examples:

Input: grid = [[0,1],[1,0],[1,1],[1,0]]
Output: 1
Explanation:
The grid is-
0 1
1 0
1 1
1 0
All lands are connected.


Input: grid = [[0,1,1,1,0,0,0],[0,0,1,1,0,1,0]]
Output: 2
Expanation:
The grid is-
0 1 1 1 0 0 0
0 0 1 1 0 2 0 
There are two islands in the grid. One island is marked by '1' and the other by '2'.

*/

// Solution in C++

#include <bits/stdc++.h>

using namespace std;

void BFS(vector<vector<bool>>&visit,int i,int j,int n,int m,vector<vector<char>>&grid){
      
  visit[i][j]=true;
  int x[]={1,1,0,-1,-1,-1,0,1};
  int y[]={0,1,1,1,0,-1,-1,-1};
  queue<pair<int,int>>q;
  q.push({i,j});
  
  while(q.empty()==false){
      
      int r=q.front().first;
      int c=q.front().second;
      q.pop();
      for(int k=0;k<8;k++){
          int newR=r+x[k];
          int newC=c+y[k];
          if(newR>=0 && newR<n && newC>=0 && newC<m && visit[newR][newC]==false && grid[newR][newC]=='1'){
              q.push({newR,newC});
              visit[newR][newC]=true;
          }
      }
      
  }
  
}
int numIslands(vector<vector<char>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<bool>>visit(n,vector<bool>(m,false));
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='1' && visit[i][j]==false){
                BFS(visit,i,j,n,m,grid);
                ans++;
            }
        }
    }
    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    for(int i = 0; i < n; i++ ){
        for ( int j = 0; j < m; j++ ) {
            cin >> v[ i ][ j ];
        }
    }
    cout << numIslands(v);
}