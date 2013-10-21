class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int n = height.size(), l[n], r[n];

        for (int i = 0; i < n; ++i) {
            l[i] = i;
            int k = i - 1;
            while (k >= 0 && height[k] >= height[i]) {
                l[i] = l[k];
                k = l[k] - 1;
            }
        }

        for (int i = n - 1; i >= 0; --i) {
            r[i] = i;
            int k = i + 1;
            while (k < n && height[k] >= height[i]) {
                r[i] = r[k];
                k = r[k] + 1;
            }
        }

        int max_area = 0;
        for (int i = 0; i < n; ++i) {
            int cur_area = (r[i] - l[i] + 1) * height[i];
            if (cur_area > max_area) max_area = cur_area;
        }

        return max_area;
    }
};
