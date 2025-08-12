def count_partitions(a, max_sum):
    partitions = 1
    subarray_sum = 0

    for num in a:
        if subarray_sum + num <= max_sum:
            subarray_sum += num
        else:
            partitions += 1
            subarray_sum = num
    return partitions

def largest_subarray_sum_minimized(a, k):
    low = max(a)
    high = sum(a)

    for max_sum in range(low, high + 1):
        if count_partitions(a, max_sum) == k:
            return max_sum
    return low

# Example usage
a = [10, 20, 30, 40]
k = 2
ans = largest_subarray_sum_minimized(a, k)
print(f"The answer is: {ans}")
