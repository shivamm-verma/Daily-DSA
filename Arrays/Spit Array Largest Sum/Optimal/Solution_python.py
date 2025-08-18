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

    # Binary search
    while low <= high:
        mid = (low + high) // 2
        partitions = count_partitions(a, mid)

        if partitions > k:
            low = mid + 1
        else:
            high = mid - 1
    return low

# Example usage
a = [10, 20, 30, 40]
k = 2
ans = largest_subarray_sum_minimized(a, k)
print(f"The answer is: {ans}")
