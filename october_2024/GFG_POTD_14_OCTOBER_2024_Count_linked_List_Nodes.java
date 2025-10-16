class Solution {
    // Function to count nodes of a linked list.
    public int getCount(Node head) {
        // code here
        int count = 0;

        if (head == null) {
            count = 0;
        } else {
            Node ptr = head;
            while (ptr != null) {
                count++;
                ptr = ptr.next;
            }
        }
        return count;
    }
}