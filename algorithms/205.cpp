//INNNNNNNnoVation!!!
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int char_s[128], char_t[128];
        memset(char_s, 0, sizeof(char_s));
        memset(char_t, 0, sizeof(char_t));
        int L_1 = s.size();
        for (int i = 0; i < L_1; i++)
        {
            if (char_s[s[i]] != char_t[t[i]]) return false;
            char_s[s[i]] = i + 1;
            char_t[t[i]] = i + 1;
        }
        return true;
    }
};