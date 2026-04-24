class Solution {
public:
    int countLive(vector<vector<int>>& curr, int i, int j, int n, int m) {
        int liveNeighbours = 0;
        if (i > 0) {
            // check the upper neighbour
            if (curr[i - 1][j] == 1)
                liveNeighbours++;
        }
        if (i < n - 1) {
            // check the lower neighbour
            if (curr[i + 1][j] == 1)
                liveNeighbours++;
        }
        if (j > 0) {
            // check the left neighbour
            if (curr[i][j - 1] == 1)
                liveNeighbours++;
        }
        if (j < m - 1) {
            // check the right neighbour
            if (curr[i][j + 1] == 1)
                liveNeighbours++;
        }

        if (i > 0 && j > 0) {
            if (curr[i - 1][j - 1] == 1)
                liveNeighbours++;
        }
        if (i > 0 && j < m - 1) {
            if (curr[i - 1][j + 1] == 1)
                liveNeighbours++;
        }
        if (i < n - 1 && j > 0) {
            if (curr[i + 1][j - 1] == 1)
                liveNeighbours++;
        }
        if (i < n - 1 && j < m - 1) {
            if (curr[i + 1][j + 1] == 1)
                liveNeighbours++;
        }
        return liveNeighbours;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        int count = 0;
        vector<vector<int>> ans = board;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int len = countLive(ans, i, j, n, m);
                if (ans[i][j] == 0) {
                    if (len == 3) {
                        board[i][j] = 1;
                    }
                } else {
                    if (len < 2 || len > 3) {
                        board[i][j] = 0;
                    }
                }
            }
        }
    }
};