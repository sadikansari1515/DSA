class Solution {
public:

    void bfs(vector<vector<char>>& grid, int r, int c,
             vector<vector<int>>& dirs) {

        queue<pair<int, int>> q;

        q.push({r, c});

        grid[r][c] = '0';

        while(!q.empty()) {

            int size = q.size();

            for(int i = 0; i < size; i++) {

                auto curr = q.front();
                q.pop();

                int cR = curr.first;
                int cC = curr.second;

                for(auto dir : dirs) {

                    int nR = cR + dir[0];
                    int nC = cC + dir[1];

                    if(nR >= grid.size() ||
                       nC >= grid[0].size() ||
                       nR < 0 ||
                       nC < 0) {
                        continue;
                    }

                    if(grid[nR][nC] == '0') {
                        continue;
                    }

                    grid[nR][nC] = '0';

                    q.push({nR, nC});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        if(grid.empty()) return 0;

        int countIslands = 0;

        vector<vector<int>> dirs = {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0}
        };

        for(int i = 0; i < grid.size(); i++) {

            for(int j = 0; j < grid[0].size(); j++) {

                if(grid[i][j] == '1') {

                    countIslands++;

                    bfs(grid, i, j, dirs);
                }
            }
        }

        return countIslands;
    }
};