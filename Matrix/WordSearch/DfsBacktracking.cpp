#include <vector>
#include <string>
using namespace std;

class WordSearch {
    vector<vector<char>> board;
    int rows, cols;

    bool dfs(int r, int c, const string &word, int index) {
        if (index == word.size()) return true;
        if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != word[index])
            return false;

        char temp = board[r][c];
        board[r][c] = '#'; // mark visited
        bool found = dfs(r+1, c, word, index+1) ||
                     dfs(r-1, c, word, index+1) ||
                     dfs(r, c+1, word, index+1) ||
                     dfs(r, c-1, word, index+1);
        board[r][c] = temp; // backtrack
        return found;
    }

public:
    WordSearch(vector<vector<char>> &b) : board(b) {
        rows = board.size();
        cols = rows ? board[0].size() : 0;
    }

    bool exist(string word) {
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (dfs(r, c, word, 0)) return true;
            }
        }
        return false;
    }
};
