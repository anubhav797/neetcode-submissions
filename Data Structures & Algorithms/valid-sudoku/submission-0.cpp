class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // rows[i][num] = whether num appeared in row i
        vector<vector<bool>> rows(9, vector<bool>(9, false));

        // cols[j][num] = whether num appeared in column j
        vector<vector<bool>> cols(9, vector<bool>(9, false));

        // boxes[k][num] = whether num appeared in box k
        vector<vector<bool>> boxes(9, vector<bool>(9, false));

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {

                if(board[i][j] == '.')
                    continue;

                int num = board[i][j] - '1';

                // Find which 3x3 box this cell belongs to
                int box = (i / 3) * 3 + (j / 3);

                // Already present?
                if(rows[i][num] || cols[j][num] || boxes[box][num])
                    return false;

                // Mark as present
                rows[i][num] = true;
                cols[j][num] = true;
                boxes[box][num] = true;
            }
        }

        return true;
    }
};