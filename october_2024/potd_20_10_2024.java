// https://www.geeksforgeeks.org/problems/sort-a-k-sorted-doubly-linked-list/1

class Solution {
    private static class DLLNodeCompare implements java.util.Comparator<DLLNode> {
        @Override
        public int compare(DLLNode a, DLLNode b) {
            return Integer.compare(a.data, b.data);
        }
    }

    public DLLNode sortAKSortedDLL(DLLNode head, int k) {
        if (head == null) {
            return head;
        }

        PriorityQueue<DLLNode> pq = new PriorityQueue<>(new DLLNodeCompare());
        DLLNode dummy = new DLLNode(-1);
        DLLNode tmp = dummy;

        // Push the first k nodes into the priority queue
        for (int i = 0; i < k && head != null; i++) {
            pq.offer(head);
            head = head.next;
        }

        // Process the rest of the nodes
        while (head != null) {
            pq.offer(head);
            head = head.next;

            tmp.next = pq.poll();
            tmp.next.prev = tmp;
            tmp = tmp.next;
        }

        // Process remaining nodes in the priority queue
        while (!pq.isEmpty()) {
            tmp.next = pq.poll();
            tmp.next.prev = tmp;
            tmp = tmp.next;
        }

        tmp.next = null; // Mark the end of the list
        dummy.next.prev = null; // Set the prev of the head to null
        return dummy.next; // Return the sorted DLL starting from the first element
    }
}
