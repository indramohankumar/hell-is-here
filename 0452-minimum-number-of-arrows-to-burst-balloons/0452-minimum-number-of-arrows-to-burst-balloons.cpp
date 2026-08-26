class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        int n = points.size();

        sort(points.begin(), points.end());

        int count = 1;
        int i = 0;
        int j = 1;

        while (j < n) {

            int ce = points[i][1];
            int ns = points[j][0];

            // Overlap
            if (ce >= ns) {
                points[i][1] = min(points[i][1], points[j][1]);
                j++;
            }


            else {
                count++;
                i = j;
                j++;
            }
        }

        return count;
    }
};