class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        result = 0
        for char in columnTitle:
            result = result * 26 + (ord(char.upper()) - ord('A') + 1)
        return result

# Taking user input
if __name__ == "__main__":
    columnTitle = input("Enter Excel column title (e.g., 'AB'): ")
    solution = Solution()
    print("Column Number is:", solution.titleToNumber(columnTitle))
