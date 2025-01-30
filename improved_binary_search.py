from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1

        while l <= r:
            if r - l < 2:  # If only 1 or 2 elements are left, use standard binary search checks
                if nums[l] == target:
                    return l
                if nums[r] == target:
                    return r
                return -1
            
            # Determine last left-half value and first right-half value
            mid = l + (r - l) // 2
            last_left_value = nums[mid]  # Last value in the left half
            first_right_value = nums[mid + 1]  # First value in the right half
            
            # Smart midpoint adjustment
            if target < last_left_value:
                m = l + (mid - l) // 2  # Skew midpoint towards the left
            elif target > first_right_value:
                m = mid + 1 + (r - (mid + 1)) // 2  # Skew midpoint towards the right
            else:
                m = mid  # Standard midpoint
            
            # Check if we've found the target
            if nums[m] == target:
                return m

            # Adjust search boundaries based on comparison
            elif nums[m] < target:
                l = m + 1  # Search the right half
            else:
                r = m - 1  # Search the left half
        
        return -1  # Target not found
