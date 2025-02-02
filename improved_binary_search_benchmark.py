import random
import timeit
from typing import List

class ImprovedSolution:
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
            last_left_value = nums[mid]       # Last value in the left half
            first_right_value = nums[mid + 1]   # First value in the right half
            
            # Smart midpoint adjustment
            if target < last_left_value:
                m = l + (mid - l) // 2         # Skew midpoint towards the left
            elif target > first_right_value:
                m = mid + 1 + (r - (mid + 1)) // 2  # Skew midpoint towards the right
            else:
                m = mid                        # Standard midpoint
            
            # Check if we've found the target
            if nums[m] == target:
                return m
            elif nums[m] < target:
                l = m + 1                    # Search the right half
            else:
                r = m - 1                    # Search the left half
        
        return -1  # Target not found

class StandardSolution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1
        while l <= r:
            mid = (l + r) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                l = mid + 1
            else:
                r = mid - 1
        return -1

# Utility function to prepare a sorted dataset of size n
def prepare_dataset(n: int) -> List[int]:
    return list(range(n))

# Benchmark helper: perform a search with a random target from the dataset
def benchmark_search(solution, dataset: List[int], iterations: int) -> float:
    def run_search():
        # Pick a random target from the dataset
        target = random.choice(dataset)
        solution.search(dataset, target)
    return timeit.timeit(run_search, number=iterations)

if __name__ == '__main__':
    iterations = 10000  # Number of iterations for each benchmark
    dataset_sizes = [5, 10, 15, 20]  # Smaller dataset sizes

    improved = ImprovedSolution()
    standard = StandardSolution()

    for size in dataset_sizes:
        dataset = prepare_dataset(size)
        time_improved = benchmark_search(improved, dataset, iterations)
        time_standard = benchmark_search(standard, dataset, iterations)
        print(f"Dataset Size: {size} elements")
        print(f"Improved Binary Search: {time_improved:.5f} seconds for {iterations} iterations")
        print(f"Standard Binary Search: {time_standard:.5f} seconds for {iterations} iterations")
        print("-------")
