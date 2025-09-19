def is_array_anagram(arr1, arr2):
    if len(arr1) != len(arr2):
        return False

    freq = {}

    # Count elements in arr1
    for num in arr1:
        freq[num] = freq.get(num, 0) + 1

    # Subtract using arr2
    for num in arr2:
        if num not in freq:
            return False
        freq[num] -= 1
        if freq[num] == 0:
            del freq[num]

    return len(freq) == 0


# Example test cases
print(is_array_anagram([1, 2, 3], [3, 2, 1]))  # True
print(is_array_anagram([1, 2, 2], [2, 1, 1]))  # False
