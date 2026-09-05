class Solution {

    int f(int i, int buy, vector<int>& prices,
          vector<vector<int>>& dp) {

        // No days left
        if (i >= prices.size()) {
            return 0;
        }

        if (dp[i][buy] != -1) {
            return dp[i][buy];
        }

        int profit = 0;

        if (buy) {

            // Buy
            int take = -prices[i] + f(i + 1, 0, prices, dp);

            // Don't buy
            int notTake = f(i + 1, 1, prices, dp);

            profit = max(take, notTake);

        } else {

            // Sell
            int sell = prices[i] + f(i + 2, 1, prices, dp);

            // Don't sell
            int notSell = f(i + 1, 0, prices, dp);

            profit = max(sell, notSell);
        }

        return dp[i][buy] = profit;
    }

public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        return f(0, 1, prices, dp);
    }
};