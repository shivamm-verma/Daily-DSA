class Solution(object):
    def groupAnagrams(self, strs):
        dic = {}
        lst = []
        for ch in strs:
            val = ''.join(sorted(ch))
            if val not in dic:
                dic[val] = []
            dic[val].append(ch)

        for value in dic.values():
            lst.append(value)
        return lst

# 🔹 User input function
if __name__ == "__main__":
    print("Enter words separated by spaces:")
    user_input = input().strip()
    words = user_input.split()

    sol = Solution()
    result = sol.groupAnagrams(words)

    print("\nGrouped Anagrams:")
    for grp in result:
        print(grp)