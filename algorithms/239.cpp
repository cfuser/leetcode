//deque
/*
maintain a queue whose value is from big to small, the deque stores index of these values
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        queue<int> q;
        for (int i = 0; i < k; i++)
        {
            while (!q.empty() && nums[i] > nums[q.front()]) q.pop();
            q.push(i);
        }
        vector<int> ans;
        for (int i = k; i <= n; i++)
        {
            ans.push_back(nums[q.front()]);
            while (!q.empty() && q.front() <= i - k) q.pop();
            while (!q.empty() && i != n && nums[i] > nums[q.back()]) q.pop();
            q.push(i);
        }
        return ans;
    }
};