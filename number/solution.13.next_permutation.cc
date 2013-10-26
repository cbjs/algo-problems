class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int i = num.size() - 1;
        while (i > 0 && num[i - 1] >= num[i]) i--;
        if (i == 0) {
            reverse(num.begin(), num.end());
            return;
        }

        int j = num.size() - 1;
        while (num[j] <= num[i - 1]) j--;

        swap(num[i - 1], num[j]);
        reverse(num.begin() + i, num.end());
    }
};
