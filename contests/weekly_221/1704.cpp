//INNNNoVation!!!
class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        set <char> ss = set <char> {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int num_1 = 0, num_2 = 0;
        for (int i = 0; i < n / 2; i++)
        num_1 += ss.find(s[i]) != ss.end(),
        num_2 += ss.find(s[n - i - 1]) != ss.end();
        return num_1 == num_2;
    }
};