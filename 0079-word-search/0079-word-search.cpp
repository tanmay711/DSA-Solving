class Solution {
public:
    int rows, cols;
    bool dfs(int r, int c, int i , vector<vector<char>> &board, string &word, vector<vector<bool>> &path)
    {
        if(i==word.size())
        {
            return true;
        }

        if(r<0 || c <0 || r==rows || c==cols || word[i] != board[r][c] || path[r][c])
        {
            return false;
        }

        path[r][c]= true;

        bool res = dfs(r+1, c, i+1, board,word,path) ||
                    dfs(r-1, c, i+1, board,word,path) ||
                    dfs(r, c+1, i+1, board,word,path) ||
                    dfs(r, c-1, i+1, board,word,path);

        path[r][c] =false;

        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
      rows = board.size();
      cols = board[0].size();
      vector<vector<bool>> path(rows, vector<bool>(cols, false));

      for(int r =0;r<rows; r++)
      {
        for(int c= 0; c<cols;c++)
        {
            if(dfs(r,c,0,board,word,path))
            {
                return true;
            }
        }
      }
      return false;
    }
};