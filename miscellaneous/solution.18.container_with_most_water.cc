class Solution {
public:
    int maxArea(vector<int> &height) {
        int n = height.size(), i = 0, j = n - 1, max_area = 0;
        while (i < j) {
            int cur_area = (j - i) * min(height[i], height[j]);
            if (max_area < cur_area) max_area = cur_area;

            if (height[i] < height[j]) {
                int k = i + 1;
                while (height[k] <= height[i] && k < j) k++;
                i = k;
            } else {
                int k = j - 1;
                while (height[k] <= height[j] && k > i) k--;
                j = k;
            }
        }
        return max_area;
    }
};
