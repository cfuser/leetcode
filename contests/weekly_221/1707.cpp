//INNNNoVation!!!
/*
forward-star
*/
class Solution {
public:
    int trie[100005 * 32][4], idx = 0;
    void insert(int x)
    {
        int p = 0;
        for (int i = 31; i >= 0; i--)
        {
            int u = (x >> i) & 1;
            if (trie[p][u] == -1)
            {
                idx++;
                trie[p][u] = idx;
                trie[idx][0] = trie[idx][1] = -1;
                trie[idx][2] = x;
            }
            p = trie[p][u];  
        }
    }
    int search(int x, int m)
    {
        int p = 0, ans = 0;
        for (int i = 31; i >= 0; i--)
        {
            //cout << trie[p][0] << " " << trie[p][1] << endl;
            //cout << trie[trie[p][0]][2] << " " << trie[trie[p][1]][2] << endl;
            int u = x >> i & 1;
            if (trie[p][u ^ 1] != -1 && trie[trie[p][u ^ 1]][2] <= m)
            {
                p = trie[p][u ^ 1];
                ans += 1 << i;
            }
            else if (trie[p][u] != -1 && trie[trie[p][u]][2] <= m)
            {
                p = trie[p][u];
                //ans += (u) * 1 << i;
            }
            else return -1;
        }
        return ans;
    }
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        trie[0][0] = trie[0][1] = -1;
        for (int i = 0; i < n; i++)
        {
            insert(nums[i]);
        }
        for (int i = idx; i >= 0; i--)
        {
            //trie[i][2] = INT_MAX;
            if (trie[i][0] != -1)
            trie[i][2] = min(trie[i][2], trie[trie[i][0]][2]);
            if (trie[i][1] != -1)
            trie[i][2] = min(trie[i][2], trie[trie[i][1]][2]);
        }
        //for (int i = 0; i <= idx; i++) cout << trie[i][0] << " " << trie[i][1] << " " << trie[i][2] << endl;
        int q = queries.size();
        vector<int> ans;
        for (int i = 0; i < q; i++)
        {
            int x = search(queries[i][0], queries[i][1]);
            ans.push_back(x);
        }
        return ans;
    }
};