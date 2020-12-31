//INNNNoVAtion!!!
/*
math derivation
orzzz
*/

class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        vector<int> g, sum = {0};
        for (int i = 0; i < n; i++)
        if (nums[i] == 1)
        {
            g.push_back(i - count);
            sum.push_back(g.back() + sum.back());
            count++;
        }
        //int m = g.size();
        int ans = INT_MAX;
        for (int i = 0; i + k <= count; i++)
        {
            int mid = (2 * i + k - 1) / 2, q = g[mid];
            ans = min(ans, (2 * (mid - i) - k + 1) * q + (sum[i + k] - sum[mid + 1]) - (sum[mid] - sum[i]));
        }
        return ans;
    }
};