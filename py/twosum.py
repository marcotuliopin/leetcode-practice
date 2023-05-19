"""
BRUTE FORCE METHOD
TIME COMPLEXITY: O(n^2) 
SPACE COMPLEXITY: O(1)
"""
def solution(nums, target):
    for i in range(len(nums)):
        for j in range(i + 1, len(nums)):
            if nums[j] == target - nums[i]:
                return [i, j]

"""
HASHTABLE METHOD
TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n)
THOUGHT PROCESS: create a hashtable where the keys are the numbers of the array
and the values are their indexes. Traverse the array and, for each element, search
for its complement in the hashtable (O(1)). If its not found, add the element to
the table.
"""
def solution2(nums, target):
    hashmap = {}
    for i in range(len(nums)):
        if target - nums[i] in hashmap:
            return [hashmap[target - nums[i]], i]
        hashmap[nums[i]] = i

