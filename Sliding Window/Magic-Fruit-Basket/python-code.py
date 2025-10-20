def total_fruits(arr):
    from collections import defaultdict

    count = defaultdict(int)
    left = 0
    max_fruits = 0

    for right in range(len(arr)):
        count[arr[right]] += 1

        while len(count) > 2:
            count[arr[left]] -= 1
            if count[arr[left]] == 0:
                del count[arr[left]]
            left += 1

        max_fruits = max(max_fruits, right - left + 1)

    return max_fruits

# Input handling
if __name__ == "__main__":
    arr = list(map(int, input().split()))
    print(total_fruits(arr))
