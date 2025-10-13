def can_be_typed_words(text, brokenLetters):
    broken = set(brokenLetters)
    count = 0

    for word in text.split():
        if all(ch not in broken for ch in word):
            count += 1

    return count


text = input("Enter the sentence: ")
brokenLetters = input("Enter broken letters (no spaces): ")

result = can_be_typed_words(text, brokenLetters)
print(f"You can type {result} word(s) without using broken letters.")