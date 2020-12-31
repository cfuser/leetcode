///INNNNNoVation!!!
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        int n = stones.size();
        for (int i = 0; i < n; i++) q.push(stones[i]);
        while (q.size() >= 2)
        {
            int x = q.top(); q.pop();
            int y = q.top(); q.pop();
            if (x != y) q.push( abs(x - y) );
        }
        if (!q.empty()) return q.top();
        else return 0;
    }
};