"""
FIRST ATTEMPT
TIME COMPLEXITY: O(n^2)
SPACE COMPLEXITY: O(1)
"""


def solution1(self, head):
    new_head = head

    if head is None:
        return head

    while (not new_head.next is None):
        new_head = new_head.next

    it = head
    reverse_it = new_head

    while (not reverse_it is head):
        if it.next == reverse_it:
            reverse_it.next = it
            reverse_it = it
            it = head
        else:
            it = it.next
    reverse_it.next = None
    return new_head


"""
SECOND (AND BETTER) ATTEMPT 
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)
"""


def solution2(self, head):
    it = head  # The current node.
    next_node = None  # The previous node in the original order.

    while not it is None:
        tmp = it.next
        it.next = next_node  # Reverse the node.
        next_node = it  # Move foward in the list.

        if tmp is None:  # Reached the end of the list.
            return it

        it = tmp  # Move to the next node.
