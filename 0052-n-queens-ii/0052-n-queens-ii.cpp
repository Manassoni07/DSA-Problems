class Solution {
    void solve(vector<string>& board, int row) {
        if (row >= N) {
            ans.push_back(board);
            return;
        }

        // for (int col = 0; col < N; col++) {
        //     if (isValid(board, row, col)) {
        //         board[row][col] = 'Q';
        //         solve(board, row + 1);
        //         board[row][col] = '.';
        //     }
        // }
        for (int cols = 0; cols < N; cols++) {
            int digconst = row + cols;
            int antidigconst = row - cols;

            if (col.find(cols) != col.end() ||
                dig.find(digconst) != dig.end(digconst) ||
                antiDig.find(antidigconst) != antiDig.end(antidigconst)) {
                    continue;
            }

            col.insert(cols);
            dig.insert(digconst);
            antiDig.insert(antidigconst);

            board[row][cols] = 'Q';
            solve(board,row+1);

            col.erase(cols);
            dig.erase(digconst);
            antiDig.erase(antidigconst);

            board[row][cols] = '.';

        }
    }
public:
     vector<vector<string>> ans;
    int N;
    unordered_set<int> col;
    unordered_set<int> dig;
    unordered_set<int> antiDig;
    int totalNQueens(int n) {
        if (n == 0)
            return 0;
        vector<string> board(n, string(n, '.'));
        N = n;

        solve(board, 0);

        return ans.size();
    }
};

