def reverse_string(s):
    l, r = 0, len(s) - 1
    while l < r:
        s[l], s[r] = s[r], s[l]
        l += 1
        r -= 1

# Main
s = list("hello")  # Convert string to list of characters
reverse_string(s)
print("".join(s))  # Output: olleh
