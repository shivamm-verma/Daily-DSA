def is_bit_set(n, i):
    # Shift 1 to the left i times and perform bitwise AND
    return (n & (1 << i)) != 0

if __name__ == "__main__":
    n, i = map(int, input().split())
    print("Yes" if is_bit_set(n, i) else "No")

"""
Time Complexity: O(1)
Space Complexity: O(1)
"""
