//INNNNNoVation!!!
class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n = apples.size();
        int ans = 0;
        priority_queue < pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > q;
        int i = 0;
        for (i = 0; i < n; i++)
        {
            while (!q.empty() && q.top().first == i) q.pop();
            if (apples[i] != 0) q.push(pair<int,int>(i + days[i], apples[i]));
            if (!q.empty())
            {
                pair<int, int> temp = q.top();
                q.pop();
                if (temp.second >= 1) ans += 1, temp.second -= 1;
                if (temp.second > 0) q.push(temp);
            }
        }

        while (!q.empty())
        {
            while (!q.empty() && q.top().first == i) q.pop();
            if (q.empty()) break;
            pair<int, int> temp = q.top();
            q.pop();
            if (temp.second >= 1) ans += 1, temp.second -= 1;
            if (temp.second > 0) q.push(temp);
            i++;
        }
        return ans;
    }
};