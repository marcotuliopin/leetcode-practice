class TreNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

"""
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(1)
THOUGHT PROCESS: recursively invert each node individually.
"""
class Solution:
    def invertTree(self, root):
        if root:
            tmp = root.left
            root.left = root.right
            root.right = tmp

            self.invertTree(root.left)
            self.invertTree(root.right)
        return root
