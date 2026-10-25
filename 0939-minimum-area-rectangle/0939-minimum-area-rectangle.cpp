class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_set<string> st;

        // Store all points in the set
        for (auto &p : points) {
            st.insert(to_string(p[0]) + "," + to_string(p[1]));
        }

        int ans = INT_MAX;

        // Consider every pair of points as diagonal corners
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {

                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                // Diagonal points must have different X and Y
                if (x1 == x2 || y1 == y2)
                    continue;

                // Check whether the other two corners exist
                string p3 = to_string(x1) + "," + to_string(y2);
                string p4 = to_string(x2) + "," + to_string(y1);

                if (st.count(p3) && st.count(p4)) {
                    int area = abs(x2 - x1) * abs(y2 - y1);
                    ans = min(ans, area);
                }
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};