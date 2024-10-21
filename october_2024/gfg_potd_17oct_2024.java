// User function Template for Java
/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
    // Function to append a new node with newData at the end of a linked list
    Node[] alternatingSplitList(Node head) {
       
  
        // Edge case: if the list is empty, return two null lists
        if (head == null) {
            return new Node[] { null, null };
        }

        // Create two dummy nodes to simplify the process of creating two sublists
        Node oddDummy = new Node(0);  // List for odd indexed elements
        Node evenDummy = new Node(0); // List for even indexed elements
        Node oddTail = oddDummy, evenTail = evenDummy;

        Node current = head; // Pointer to traverse the original list
        boolean isOdd = true; // Flag to determine whether the current node is odd or even

        // Traverse the original linked list
        while (current != null) {
            if (isOdd) {
                // Append current node to the odd list
                oddTail.next = current;
                oddTail = oddTail.next;
            } else {
                // Append current node to the even list
                evenTail.next = current;
                evenTail = evenTail.next;
            }
            // Move to the next node
            current = current.next;

            // Alternate between odd and even nodes
            isOdd = !isOdd;
        }

        // End both lists properly
        oddTail.next = null;
        evenTail.next = null;

        // Return the heads of the two lists (ignoring the dummy nodes)
        return new Node[] { oddDummy.next, evenDummy.next };
    }
}
