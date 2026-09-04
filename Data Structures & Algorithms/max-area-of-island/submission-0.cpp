class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        vector<vector<int>> vis(m, vector<int>(n, 0));

        int maxArea = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 1 && !vis[i][j]) {

                    queue<pair<int,int>> q;

                    q.push({i, j});
                    vis[i][j] = 1;

                    int area = 0;

                    while(!q.empty()) {

                        auto [row, col] = q.front();
                        q.pop();

                        // We visited one land cell
                        area++;

                        for(int k = 0; k < 4; k++) {

                            int nrow = row + delrow[k];
                            int ncol = col + delcol[k];

                            if(nrow >= 0 && nrow < m &&
                               ncol >= 0 && ncol < n &&
                               !vis[nrow][ncol] &&
                               grid[nrow][ncol] == 1) {

                                vis[nrow][ncol] = 1;
                                q.push({nrow, ncol});
                            }
                        }
                    }

                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};