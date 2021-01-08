//INNNNoVation!!!

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visit(n, 0);
        queue<int> q;
        int ans = 0;

        for (int i = 0; i < n; i++)
        if (visit[i] == 0)
        {
            ans++;
            visit[i] = 1;
            q.push(i);
            while (!q.empty())
            {
                int x = q.front();
                for (int j = 0; j < n; j++)
                if (visit[j] == 0 && isConnected[x][j] == 1)
                {
                    q.push(j);
                    visit[j] = 1;
                }
                q.pop();
            }
        }
        return ans;
    }
};