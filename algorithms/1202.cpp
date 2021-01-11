//INNNoVation!!!

/*
vector<char> str[];
*/

class Solution {
public:
    static const int N = 1e5 + 5;
    struct Node
    {
        int p;
        int r;
    };
    Node node[N];

    int get(int x)
    {
        if (node[x].p == x) return x;
        return node[x].p = get(node[x].p);
    }
    int _union(int x, int y)
    {
        x = get(x); y = get(y);
        if (x == y) return 0;
        if (node[x].r == node[y].r) node[x].r++;
        if (node[x].r > node[y].r)
        {
            node[y].p = x;
        }
        else
        {
            node[x].p = y;
        }
        return 0;
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = pairs.size();
        int size = s.size();
        for (int i = 0; i < size; i++)
        {
            node[i].p = i;
            node[i].r = 0;
        }
        for (int i = 0; i < n; i++)
        {
            int x = pairs[i][0], y = pairs[i][1];
            _union(x, y);
        }
        for (int i = 0; i < size; i++) get(i);
        
        vector<char> str[size];
        for (int i = 0; i < size; i++)
        {
            int x = node[i].p;
            char y = s[i];
            str[x].push_back(y);
        }
        for (int i = 0; i < size; i++) sort(str[i].begin(), str[i].end());
        vector<int> head(size, 0);
        string ans;
        for (int i = 0; i < size; i++)
        {
            ans += str[node[i].p][head[node[i].p]];
            head[node[i].p]++;
        }
        return ans;
    }
};