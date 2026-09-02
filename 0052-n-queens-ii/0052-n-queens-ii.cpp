class Solution {
public:
    int ans=0;
    bool issafe(int row, int col, vector<vector<char>> &board, int n)
    {
        for(int j=0;j<col;j++)
        {
            if(board[row][j]=='Q')
            {
                return false;
            }
        }
        for(int i=row, j=col;i>=0 && j>=0;i--, j--)
        {
            if(board[i][j]=='Q')
            {
                return false;
            }
        }
        for(int i=row, j=col;i<n && j>=0 ; i++, j--)
        {
            if(board[i][j]=='Q')
            {
                return false;
            }
        }
        return true;
    }
    void solve(int col, vector<vector<char>> &board, int n)
    {
        if(col==n)
        {
            ans++;
            return;
        }
        for(int row = 0; row<n;row++)
        {
            if(issafe(row, col, board, n))
            {
                board[row][col]='Q';
                solve(col+1, board, n);
                board[row][col] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n,'.'));
        solve(0,board, n);
        return ans;
    }
};