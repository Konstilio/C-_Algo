class Solution {
public:
    char spec;

    Solution()
    {
        spec = static_cast<char>(1);
    }

    bool dfs(vector<vector<char>> &board, string const &word, int curr, int i, int j, int height, int width)
    {
        if (i >= height || i < 0 || j >= width || j < 0)
            return false;
        
        if (board[i][j] != word[curr])
            return false;
        
        if (curr == word.size() - 1)
            return true;
       
        char prev =  board[i][j];     
        board[i][j] = spec;

        if 
            (
                dfs(board, word, curr + 1, i + 1, j, height, width)
                || dfs(board, word, curr + 1, i - 1, j, height, width)
                || dfs(board, word, curr + 1, i, j + 1, height, width)
                || dfs(board, word, curr + 1, i, j - 1, height, width)
            )
        {
            return true;
        }

        board[i][j] = prev;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty())
            return false;
        
        if (word.empty())
            return false;
        
        int height = board.size();
        int width = board[0].size();

        for (int i = 0; i < height; ++i)
        {
            for (int j = 0; j < width; ++j)
            {
                if (dfs(board, word, 0, i, j, height, width))
                    return true;
            }
        }
        
        return false;
    }

};