class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        // Treat the matrix as a virtually flattened sorted array
        int low = 0;
        int high = (n * m) - 1;

        while (low <= high) {

            // Calculate the middle virtual index
            int mid = low + (high - low) / 2;

            // Convert the virtual index into row and column
            int row = mid / m;
            int col = mid % m;

            // Target found
            if (matrix[row][col] == target) {
                return true;
            }

            // Current value is smaller, so search the right half
            else if (matrix[row][col] < target) {
                low = mid + 1;
            }

            // Current value is greater, so search the left half
            else {
                high = mid - 1;
            }
        }

        return false;
    }
};