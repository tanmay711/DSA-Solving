// row[i][num]	Number already exists in row i
// col[j][num]	Number already exists in column j
// box[b][num]	Number already exists in box b

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9]= {0};
        bool col[9][9]= {0};
        bool box[9][9] = {0};

        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                {
                    continue;
                }

                int number = board[i][j]-'1'; // 0based indexing
                int boxindex = (i/3)*3+(j/3);

                if(row[i][number] || col[j][number] || box[boxindex][number])
                {
                    return false;
                }

                row[i][number] = true;
                col[j][number] = true;
                box[boxindex][number] = true;

            }
        }
        return true;

    }
};