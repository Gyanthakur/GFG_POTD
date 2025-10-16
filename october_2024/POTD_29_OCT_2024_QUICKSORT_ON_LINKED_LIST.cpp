#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct Node
{
    int data;
    Node *next;

    Node(int val) : data(val), next(nullptr) {}
};

class Solution
{
public:
    /**
     * Optimized QuickSort implementation for Linked List
     * Time Complexity: O(n log n) average case, O(n²) worst case
     * Space Complexity: O(log n) due to recursion stack
     *
     * Algorithm:
     * 1. Choose last node as pivot
     * 2. Partition list around pivot (smaller elements before, larger after)
     * 3. Recursively sort sublists before and after pivot
     * 4. No extra space needed for merging (in-place sorting)
     */
    Node *quickSort(Node *head)
    {
        if (!head || !head->next)
            return head;

        // Find tail node for partitioning
        Node *tail = getTail(head);

        // Perform quicksort
        quickSortRecursive(head, tail);

        return head;
    }

private:
    /**
     * Recursive QuickSort function
     * @param head: Start of the current sublist
     * @param tail: End of the current sublist
     */
    void quickSortRecursive(Node *head, Node *tail)
    {
        if (!head || head == tail || head->next == tail->next)
        {
            return;
        }

        // Partition around pivot (tail node)
        Node *pivot = partition(head, tail);

        // Recursively sort left part (before pivot)
        if (pivot != head)
        {
            Node *leftTail = getNodeBefore(head, pivot);
            quickSortRecursive(head, leftTail);
        }

        // Recursively sort right part (after pivot)
        if (pivot->next != tail->next)
        {
            quickSortRecursive(pivot->next, tail);
        }
    }

    /**
     * Partition function using last node as pivot
     * Rearranges nodes so smaller elements come before pivot
     * @param head: Start of sublist
     * @param tail: End of sublist (pivot node)
     * @return: Final position of pivot after partitioning
     */
    Node *partition(Node *head, Node *tail)
    {
        int pivotData = tail->data;
        Node *i = nullptr; // Last node with value <= pivot

        // Traverse from head to tail (exclusive)
        for (Node *j = head; j != tail; j = j->next)
        {
            if (j->data <= pivotData)
            {
                // Move smaller element to left partition
                if (i == nullptr)
                {
                    i = head;
                }
                else
                {
                    i = i->next;
                }

                // Swap data between i and j
                swap(i->data, j->data);
            }
        }

        // Place pivot in correct position
        if (i == nullptr)
        {
            i = head;
        }
        else
        {
            i = i->next;
        }

        swap(i->data, tail->data);
        return i;
    }

    /**
     * Helper function to get the tail node
     */
    Node *getTail(Node *head)
    {
        while (head && head->next)
        {
            head = head->next;
        }
        return head;
    }

    /**
     * Helper function to get node before target node
     */
    Node *getNodeBefore(Node *head, Node *target)
    {
        if (head == target)
            return nullptr;

        while (head && head->next != target)
        {
            head = head->next;
        }
        return head;
    }
};

/**
 * Utility Functions for Linked List Operations
 */
class LinkedListUtils
{
public:
    // Create linked list from array
    static Node *createList(int arr[], int n)
    {
        if (n == 0)
            return nullptr;

        Node *head = new Node(arr[0]);
        Node *current = head;

        for (int i = 1; i < n; i++)
        {
            current->next = new Node(arr[i]);
            current = current->next;
        }

        return head;
    }

    // Print linked list
    static void printList(Node *head)
    {
        while (head)
        {
            cout << head->data;
            if (head->next)
                cout << " -> ";
            head = head->next;
        }
        cout << endl;
    }

    // Get list length
    static int getLength(Node *head)
    {
        int count = 0;
        while (head)
        {
            count++;
            head = head->next;
        }
        return count;
    }

    // Delete entire list to free memory
    static void deleteList(Node *head)
    {
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Main function for demonstration
int main()
{
    Solution solution;

    // Example usage
    int arr[] = {3, 1, 4, 1, 5, 9, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original List: ";
    Node *head = LinkedListUtils::createList(arr, n);
    LinkedListUtils::printList(head);

    cout << "Sorted List: ";
    head = solution.quickSort(head);
    LinkedListUtils::printList(head);

    // Clean up memory
    LinkedListUtils::deleteList(head);

    return 0;
}