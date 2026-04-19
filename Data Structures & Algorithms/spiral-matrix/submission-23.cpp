class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> nums;
        int n = matrix.size();
        int m = matrix[0].size();
        int lx = 0, ly = 0, rx = m - 1, ry = n - 1;

        while (lx <= rx && ly <= ry) {
            // Traverse top row
            for (int j = lx; j <= rx; j++) {
                nums.push_back(matrix[ly][j]);
            }
            ly++; // Move top boundary down

            // Traverse right column
            for (int i = ly; i <= ry; i++) {
                nums.push_back(matrix[i][rx]);
            }
            rx--; // Move right boundary left

            // Traverse bottom row (if still within bounds)
            if (ly <= ry) {
                for (int j = rx; j >= lx; j--) {
                    nums.push_back(matrix[ry][j]);
                }
                ry--; // Move bottom boundary up
            }

            // Traverse left column (if still within bounds)
            if (lx <= rx) {
                for (int i = ry; i >= ly; i--) {
                    nums.push_back(matrix[i][lx]);
                }
                lx++; // Move left boundary right
            }
        }

        return nums;
    }
};
