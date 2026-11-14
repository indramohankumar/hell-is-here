class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for(auto &row : grid) {
            sort(row.begin(), row.end());
        }

        int ans = 0;

        for(int i = 0; i < m; i++) {
            int maxi = 0;

            for(int j = 0; j < n; j++) {
                maxi = max(maxi, grid[j][m-1-i]);
            }

            ans += maxi;
        }

        return ans;
    }
};