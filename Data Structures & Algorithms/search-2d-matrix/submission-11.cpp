class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int lo = 0;
        int m = matrix.size();
        int hi = m - 1;
        int mid = (lo + hi) / 2;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            int n = matrix[mid].size();
            if (matrix[mid][0] <= target && target <= matrix[mid][n - 1]) break;
            else if (matrix[mid][0] >= target && matrix[mid][n-1] >= target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        int target_row = mid;
        int n = matrix[mid].size();
        lo = 0;
        hi = n - 1;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if (matrix[target_row][mid] == target) return true;
            else if (matrix[target_row][mid] > target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return false;

    }
};
