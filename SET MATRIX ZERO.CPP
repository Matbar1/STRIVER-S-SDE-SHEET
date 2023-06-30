class Solution {
public:
   void setZeroes(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size();
        vector<bool> row(M), col(N);
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                row[i] = row[i] || A[i][j] == 0;
                col[j] = col[j] || A[i][j] == 0;
            }
        }
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (row[i] || col[j]) A[i][j] = 0;
            }
        }
    }
};