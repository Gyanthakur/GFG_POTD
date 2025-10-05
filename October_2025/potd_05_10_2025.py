class Solution:
    def ratInMaze(self, maze):
        def Traverse(i,j,res):
            if i<0 or j<0 or i>=n or j>=m or maze[i][j]!=1:
                return 
            if i==n-1 and j==m-1:
                result.append(res)
                return
            maze[i][j]=-1
            Traverse(i-1,j,res+"U")
            Traverse(i+1,j,res+"D")
            Traverse(i,j-1,res+"L")
            Traverse(i,j+1,res+"R")
            maze[i][j]=1
                
        result=[]
        n=len(maze)
        m=len(maze[0])
        if maze[0][0]==1:
            Traverse(0,0,"")
        return sorted(result)