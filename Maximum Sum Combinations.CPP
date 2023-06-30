int maxSumCombination(vector<int> &A, vector<int> &B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int i = A.size() - 1;
    int j = B.size() - 1;
    int max_sum = 0;

    while (i >= 0 && j >= 0) {
        int current_sum = A[i] + B[j];
        max_sum = max(max_sum, current_sum);

        if (A[i] >= B[j]) {
            i--;
        } else {
            j--;
        }
    }

    return max_sum;
}