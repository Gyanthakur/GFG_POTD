

// User function Template for Java

/*class Node

class Node
{
   int data;
   Node right,down;

   Node(int data){
       this.data = data;
       right = null;
       down = null;
   }
}
*/
/*Function should return the head of the 2D LL.*/
class Solution {
    static Node head;
    static Node construct(int arr[][]) {
        // Add your code here.
        int n=arr.length;
        
        if(n==1)
        {
            Node newnode =new Node(arr[0][0]); 
            head=newnode;
            return head;
        }
        
        Node newnode =new Node(arr[0][0]); 
        head=newnode;
        
        Node currnode=newnode;
        Node firstnode=head;
        Node secondnode=head;
        
        for(int i=0;i<n;i++)
        {
            
            if(i>0)
            {
                
                Node newnode3=new Node(arr[i][0]);
                firstnode.down=newnode3;
                
                currnode=newnode3;
                firstnode=firstnode.down;
               
            }
            
    
            for(int j=1;j<n;j++)
            {
                Node newnode2=new Node(arr[i][j]);
                currnode.right=newnode2;
                currnode=currnode.right;
            }
            
        }
        
        firstnode = head;
        while (firstnode.down != null) 
        {
            Node row1 = firstnode;
            Node row2 = firstnode.down;

            while (row1 != null && row2 != null) 
            {
                row1.down = row2;
                row1 = row1.right;
                row2 = row2.right;
            }

            firstnode = firstnode.down;
        }
        
        
        return head;
    }
}
