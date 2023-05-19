"""
ALL CODED SOLUTION
TIME COMPLEXITY: O(log n)
SPACE COMPLEXITY: O(1)
THOUGHT PROCESS: Tried to implement a binary search top to bottom.
"""
def solution(self, nums, target):
    left = 0
    right = len(nums) - 1

    while left <= right:
        middle = left + (right - left) // 2 # The double slash represents a
                                            # integer division operator.
        if nums[middle] >= target:
            right = middle - 1
        else:
            left = middle + 1
    return left
