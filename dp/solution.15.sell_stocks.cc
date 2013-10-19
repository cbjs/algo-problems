class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) return 0;
        int n = prices.size(), p1[n], p2[n];

        int first = prices[0], maxp = 0;
        p1[0] = 0;
        for (int i = 1; i < n; ++i) {
            if (maxp < prices[i] - first)
                maxp = prices[i] - first;
            p1[i] = maxp;
            if (first > prices[i]) first = prices[i];
        }

        first = prices[n - 1], maxp = 0;
        p2[n - 1] = 0;
        for (int i = n - 2; i >= 0; --i) {
            if (maxp < first - prices[i])
                maxp = first - prices[i];
            p2[i] = maxp;

            if (first < prices[i]) first = prices[i];
        }

        int max_profit = max(p1[n - 1], p2[0]);
        for (int i = 0; i < n - 1; ++i) {
            int cur_profit = p1[i] + p2[i + 1];
            if (max_profit < cur_profit) max_profit = cur_profit;
        }
        return max_profit;
    }
};
