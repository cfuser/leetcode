//INNNNoVaion!!!

/*
a great idea
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        for (int i = 0; i < (n - k) / 2; i++)
        {
            swap(nums[i], nums[n - k - i - 1]);
        }
        for (int i = n - k; i <= (n - k + n - 1) / 2; i++)
        {
            swap(nums[i], nums[n - (i - (n - k)) - 1]);
        }
        for (int i = 0; i < n / 2; i++)
        {
            swap(nums[i], nums[n - i - 1]);
        }
        return ;
    }
};