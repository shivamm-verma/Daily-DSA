def mergeSort(arr, low, mid, high):
    """
    Merge two sorted subarrays:
    - First subarray: arr[low ... mid]
    - Second subarray: arr[mid+1 ... high]
    Merge them into a sorted subarray.
    """
    temp = []
    left = low
    right = mid + 1

    # Merge elements from both halves in sorted order
    while left <= mid and right <= high:
        if arr[left] <= arr[right]:
            temp.append(arr[left])
            left += 1
        else:
            temp.append(arr[right])
            right += 1

    # Append remaining elements from the left half (if any)
    while left <= mid:
        temp.append(arr[left])
        left += 1

    # Append remaining elements from the right half (if any)
    while right <= high:
        temp.append(arr[right])
        right += 1

    # Copy the sorted elements back into the original array
    for i in range(low, high + 1):
        arr[i] = temp[i - low]


def merge(arr, low, high):
    """
    Recursive merge sort function:
    - Divide the array into halves
    - Recursively sort each half
    - Merge the sorted halves
    """
    if low >= high:
        return

    mid = (low + high) // 2
    merge(arr, low, mid)          
    merge(arr, mid + 1, high)     
    mergeSort(arr, low, mid, high)  


# Input section
n = int(input("Enter the size of the array: "))
arr = []

print("Enter the elements of the array: ")
for _ in range(n):
    arr.append(int(input()))

# Run merge sort
merge(arr, 0, n - 1)

# Print the sorted array
print("\nArray after sorting: ", end="")
for i in arr:
    print(i, end=" ")
print()
