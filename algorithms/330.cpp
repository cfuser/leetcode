//INNNNNNnoVation!!!
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int L = nums.size();
        long long sum = 1;
        int extra = 0;
        for (int i = 0; i < L; i++)
        //if (sum <= n)
        {
            while (sum < nums[i] && sum <= n) sum += sum, extra += 1;
            sum += nums[i];
        }
        while (sum <= n) sum += sum, extra += 1;
        return extra;
    }
};