from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1

        while l <= r:
            # Dynamically calculate the midpoint
            if target < nums[l]:
                m = l  # Skew towards left
            elif target > nums[r]:
                m = r  # Skew towards right
            else:
                m = l + (r - l) // 2  # Standard midpoint calculation
            
            # Search logic
            if nums[m] == target:
                return m
            elif nums[m] < target:
                l = m + 1
            else:
                r = m - 1

        return -1