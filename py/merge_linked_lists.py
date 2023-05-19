class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


"""
TWO POINTERS APROACH
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)
"""


def mergeTwoLists(self, list1, list2):

    if list1 is None:
        return list2
    elif list2 is None:
        return list1

    if list1.val < list2.val:
        list3 = list1
        list1 = list1.next
    else:
        list3 = list2
        list2 = list2.next

    it3 = list3

    while (not list1 is None) and (not list2 is None):
        if list1.val < list2.val:
            it3.next = list1
            list1 = list1.next
        else:
            it3.next = list2
            list2 = list2.next
        it3 = it3.next

    if not list1 is None:
        it3.next = list1
    elif not list2 is None:
        it3.next = list2

    return list3
