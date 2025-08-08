def removeDuplicateLetters(s: str) -> str:
    last_index = {c: i for i, c in enumerate(s)}
    seen = set()
    stack = []

    for i, c in enumerate(s):
        if c in seen:
            continue
        while stack and stack[-1] > c and i < last_index[stack[-1]]:
            seen.remove(stack.pop())
        stack.append(c)
        seen.add(c)

    return ''.join(stack)

if __name__ == "__main__":
    s = "bcabc"
    result = removeDuplicateLetters(s)
    print("Result after removing duplicate letters:", result)
