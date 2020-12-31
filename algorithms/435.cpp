//INNNNoVation!!!
class Solution {
public:
    static bool cmp(const vector<int> &x, const vector<int> &y)
    {
        return x[1] < y[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);
        int max = 0, right = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            while (intervals[i][0] >= right)
            {
                max++;
                right = intervals[i][1];
            }
        }
        return n - max;
    }
};