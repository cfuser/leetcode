//INNNoVatino!!!
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector< vector< int > > ans;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            int j = i;
            while (j < n - 1 && s[j] == s[j + 1]) j = j + 1;
            if (j - i + 1 >= 3) ans.push_back( vector< int >{i, j} );
            i = j;
        }
        return ans;
    }
};