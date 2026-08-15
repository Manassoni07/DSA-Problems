class Solution {
public:
    typedef pair<int, int> P;
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<P> q;

        int freshOcount = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshOcount++;
                }
            }
        }

        if(freshOcount == 0) return 0;

        int minutes = 0;

        auto isSafe = [&](int x, int y) {
            return x >= 0 && x < grid.size() && y >= 0 && y < grid[x].size() &&
                   grid[x][y] == 1;
        };

        while (!q.empty()) {
            int N = q.size();
            while (N--) {
                P curr = q.front();
                q.pop();

                int i = curr.first;
                int j = curr.second;

                // now we use direction array

                for (auto& dir : directions) {
                    int n_i = i + dir[0];
                    int n_j = j + dir[1];

                    if (isSafe(n_i, n_j)) {
                        grid[n_i][n_j] = 2;
                        q.push({n_i, n_j});
                        freshOcount--;
                    }
                }
            }
            minutes++;
        }

        return freshOcount == 0 ? (minutes - 1) : -1;
    }
};