def quickSort(head):
    if head is None or head.next is None:
        return head

    def partition(head, end):
        pivot = head.data
        lesser_head = lesser_tail = Node(0)
        equal_head = equal_tail = Node(0)
        greater_head = greater_tail = Node(0)

        current = head
        while current != end:
            if current.data < pivot:
                lesser_tail.next = current
                lesser_tail = lesser_tail.next
            elif current.data == pivot:
                equal_tail.next = current
                equal_tail = equal_tail.next
            else:
                greater_tail.next = current
                greater_tail = greater_tail.next
            current = current.next


        lesser_tail.next = equal_tail.next = greater_tail.next = None

        return lesser_head.next, equal_head.next, greater_head.next

    def concatenate(lesser, equal, greater):
        dummy_head = Node(0)
        current = dummy_head

        current.next = lesser
        while current.next:
            current = current.next

        current.next = equal
        while current.next:
            current = current.next

        current.next = greater
        return dummy_head.next

    lesser, equal, greater = partition(head, None)

    lesser = quickSort(lesser)
    greater = quickSort(greater)

    sorted_head = concatenate(lesser, equal, greater)
    return sorted_head
