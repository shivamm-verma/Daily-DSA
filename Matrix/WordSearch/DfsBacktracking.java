public class WordSearch {
    private char[][] board;
    private int rows, cols;

    public WordSearch(char[][] board) {
        this.board = board;
        this.rows = board.length;
        this.cols = board[0].length;
    }

    private boolean dfs(int r, int c, String word, int index) {
        if (index == word.length()) return true;
        if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != word.charAt(index))
            return false;

        char temp = board[r][c];
        board[r][c] = '#'; // mark visited
        boolean found = dfs(r+1, c, word, index+1) ||
                        dfs(r-1, c, word, index+1) ||
                        dfs(r, c+1, word, index+1) ||
                        dfs(r, c-1, word, index+1);
        board[r][c] = temp; // backtrack
        return found;
    }

    public boolean exist(String word) {
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (dfs(r, c, word, 0)) return true;
            }
        }
        return false;
    }
}
