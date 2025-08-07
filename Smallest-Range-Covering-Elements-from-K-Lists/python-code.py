import heapq

class Solution:
    def smallestRange(self, nums: list[list[int]]) -> list[int]:
        min_heap = []
        max_val = float('-inf')

        for i in range(len(nums)):
            if nums[i]:
                heapq.heappush(min_heap, (nums[i][0], i, 0))
                max_val = max(max_val, nums[i][0])

        min_range_size = float('inf')
        range_start = -1
        
        while len(min_heap) == len(nums):
            min_val, list_idx, elem_idx = heapq.heappop(min_heap)

            if max_val - min_val < min_range_size:
                min_range_size = max_val - min_val
                range_start = min_val

            if elem_idx + 1 < len(nums[list_idx]):
                next_val = nums[list_idx][elem_idx + 1]
                heapq.heappush(min_heap, (next_val, list_idx, elem_idx + 1))
                max_val = max(max_val, next_val)
            else:
                break
        
        return [range_start, range_start + min_range_size]