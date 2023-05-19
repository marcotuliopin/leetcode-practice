from typing import List

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        length = len(nums1) + len(nums2)
        half = length // 2

        if len(nums1) > len(nums2):
            nums1, nums2 = nums2, nums1

        l = 0
        r = len(nums1) - 1
        mid = len(nums1) // 2

        while (l < r):
            mid = (l + r) // 2 # nums1
            i = half - mid - 2 # nums2