class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();       // Number of rows
        int m = matrix[0].size();    // Number of columns
        
        // Treat 2D grid as a 1D range from index 0 to (total elements - 1)
        int low = 0, high = n * m - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2; // Find 1D middle index
            
            // Map 1D mid index to 2D row & col indices
            int row = mid / m;
            int col = mid % m;
            
            // Standard Binary Search Checks
            if (matrix[row][col] == target) {
                return true; // Target found
            } else if (matrix[row][col] < target) {
                low = mid + 1; // Target is in the right half
            } else {
                high = mid - 1; // Target is in the left half
            }
        }
        
        return false; // Target not present
    }
};