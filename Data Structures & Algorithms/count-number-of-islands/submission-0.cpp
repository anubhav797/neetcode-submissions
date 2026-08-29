class Solution {

    void bfs(int row , int col , vector<vector<int>> &vis , vector<vector<char>>& grid) {
        vis[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row , col});

        int m = grid.size();
        int n = grid[0].size();

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            //traverse the neighbours
            int delrow[] = {-1 , 0 , 1 , 0};
            int delcol[] = {0 , 1 , 0 , -1};
            for(int i = 0 ; i < 4 ; i++){
                    int newRow = row + delrow[i];
                    int newCol = col + delcol[i];
                    if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && !vis[newRow][newCol] && grid[newRow][newCol] == '1'){
                        q.push({newRow , newCol});
                        vis[newRow][newCol] = 1;
                    }
                }
            }
        }
      
public:
    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<vector<int>> vis(m , vector<int>(n , 0));

        for(int row = 0 ; row < m ; row++){
            for(int col = 0 ; col < n ; col++){
                if(!vis[row][col] && grid[row][col] == '1'){
                    bfs(row , col , vis , grid);
                    count++;
                }
            }
        }

        return count;
        
    }
};