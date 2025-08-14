from typing import List

class WordSearch:
    def __init__(self, board: List[List[str]]):
        self.board = board
        self.rows = len(board)
        self.cols = len(board[0]) if board else 0

    def dfs(self, r: int, c: int, word: str, index: int) -> bool:
        if index == len(word):
            return True
        if r < 0 or r >= self.rows or c < 0 or c >= self.cols or self.board[r][c] != word[index]:
            return False

        temp = self.board[r][c]
        self.board[r][c] = '#'  # mark visited
        found = (self.dfs(r+1, c, word, index+1) or
                 self.dfs(r-1, c, word, index+1) or
                 self.dfs(r, c+1, word, index+1) or
                 self.dfs(r, c-1, word, index+1))
        self.board[r][c] = temp  # backtrack
        return found

    def exist(self, word: str) -> bool:
        for r in range(self.rows):
            for c in range(self.cols):
                if self.dfs(r, c, word, 0):
                    return True
        return False
