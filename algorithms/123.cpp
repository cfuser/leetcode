//INNNNoVation!!!

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int k = min(2, n / 2);
        if (n == 0) return 0;
        int dp[n][k + 1][2];
        for (int i = 0; i < k + 1; i++)
        dp[0][i][0] = dp[0][i][1] = INT_MIN / 2;
        dp[0][0][0] = 0; dp[0][0][1] = -prices[0];
        for (int i = 1; i < n; i++)
            for (int j = 0; j < k + 1; j++)
            {
                if (j == 0) dp[i][0][0] = 0;
                else dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j - 1][1] + prices[i]);
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j][0] - prices[i]);
            }
        int ans = 0;
        for (int i = 0; i < k + 1; i++) ans = max(ans, dp[n - 1][i][0]); 
        return ans;
    }
};