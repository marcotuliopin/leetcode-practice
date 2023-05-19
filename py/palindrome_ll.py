# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    '''
    AUXILIARY ARRAY SOLUTION
    TIME COMPLEXITY: O(n)
    SPACE COMPLEXITY: O(1)
    THOUGHT PROCESS: A palindrome have its first half equals to its second half. That way, I need to find the
    middle point. After this, comes the problem of how to traverse the linked list from right to left, since
    it is a singly linked list. So I reversed only the second half of the list. Finally, its only a matter of
    traversing the linked list through both sides simultaneously and compair each node value.
    '''
    def solution(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        # find middle
        fast = head
        slow = head
        while fast.next:
            slow = slow.next
            fast = fast.next.next
        # reverse second half of the list
        next_node = None
        slow = slow.next
        while slow:
            tmp = slow.next
            slow.next = next_node
            next_node = slow
            slow = tmp
        # traverse the list from both sides and check if its palindrome 
        while head != fast:
            if head.val != fast.val or fast:
                return False
            head = head.next
            fast = fast.next
        return True
            

        


