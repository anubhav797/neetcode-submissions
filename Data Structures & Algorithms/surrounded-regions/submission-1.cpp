class Solution {

private:
    void dfs(int row, int col, vector<vector<int>>& vis,
             vector<vector<char>>& mat,
             int delrow[], int delcol[]) {

        vis[row][col] = 1;

        int m = mat.size();
        int n = mat[0].size();

        for(int i = 0; i < 4; i++) {

            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 && nrow < m &&
               ncol >= 0 && ncol < n &&
               !vis[nrow][ncol] &&
               mat[nrow][ncol] == 'O') {

                dfs(nrow, ncol, vis, mat, delrow, delcol);
            }
        }
    }

public:
    void solve(vector<vector<char>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        vector<vector<int>> vis(m, vector<int>(n, 0));

        // First row and last row
        for(int j = 0; j < n; j++) {

            if(mat[0][j] == 'O' && !vis[0][j]) {
                dfs(0, j, vis, mat, delrow, delcol);
            }

            if(mat[m-1][j] == 'O' && !vis[m-1][j]) {
                dfs(m-1, j, vis, mat, delrow, delcol);
            }
        }

        // First column and last column
        for(int i = 0; i < m; i++) {

            if(mat[i][0] == 'O' && !vis[i][0]) {
                dfs(i, 0, vis, mat, delrow, delcol);
            }

            if(mat[i][n-1] == 'O' && !vis[i][n-1]) {
                dfs(i, n-1, vis, mat, delrow, delcol);
            }
        }

        // Convert surrounded O's into X
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(mat[i][j] == 'O' && !vis[i][j]) {
                    mat[i][j] = 'X';
                }
            }
        }
    }
};