keypad = [
    "",    # 0
    "",    # 1
    "abc", # 2
    "def", # 3
    "ghi", # 4
    "jkl", # 5
    "mno", # 6
    "pqrs",# 7
    "tuv", # 8
    "wxyz" # 9
]

def solve(digits, index, path, result):
    if index == len(digits):
        result.append(path)
        return
    
    letters = keypad[int(digits[index])]
    for ch in letters:
        solve(digits, index + 1, path + ch, result)

def letter_combinations(digits):
    result = []
    if not digits:
        return result
    solve(digits, 0, "", result)
    return result

# Driver code
if __name__ == "__main__":
    digits = input("Enter digits: ")
    combos = letter_combinations(digits)
    for s in combos:
        print(s, end=" ")
