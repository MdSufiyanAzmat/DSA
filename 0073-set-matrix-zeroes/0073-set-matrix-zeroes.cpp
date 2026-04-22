class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        
        int n = matrix.size();        // Number of rows
        int m = matrix[0].size();     // Number of columns
        
        // Store which rows and columns need to be zeroed
        vector<bool> zeroRow(n, false);
        vector<bool> zeroCol(m, false);
        
        // First pass: find all zeros
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 0){
                    zeroRow[i] = true;
                    zeroCol[j] = true;
                }
            }
        }
        
        // Second pass: set zeros
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(zeroRow[i] || zeroCol[j]){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};