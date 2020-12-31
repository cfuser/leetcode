//INNNoVation!!!
class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        int minn = 0, maxx = 0;
        double tot = 0;
        for (int i = 0; i < n; i++)
        {
            if (maxx < customers[i][0]) maxx = customers[i][0];
            maxx += customers[i][1];
            tot += (maxx - customers[i][0]);
        }
        return tot / n;
    }
};