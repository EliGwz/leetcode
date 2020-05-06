class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int y = matrix.size();
        if (y == 0) return false;
        int x = matrix[0].size();
        if (x == 0) return false;

        x--;
        y = 0;
        
        while (x >= 0 && y < matrix.size()) {
            if (matrix[y][x] == target) return true;
            else if (matrix[y][x] > target) {
                x--;
            } else {
                y++;
            }
        }
        return false;
    }
};