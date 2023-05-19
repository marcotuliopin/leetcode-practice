# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
'''
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)
THOUGHT PROCESS: taking the same process made in the ./palindrome_ll.py.
'''
class Solution(object):
    def pairSum(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: int
        """
        # find middle
        slow = head
        fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        # reverse second half
        next_node = None
        while slow:
            tmp = slow.next
            slow.next = next_node
            next_node = slow
            slow = tmp
        # find biggest twin sum
        left, right = head, next_node
        bigger = 0
        while right:
            num = left.val + right.val
            if num > bigger:
                bigger = num
            left = left.next
            right = right.next
        return bigger
