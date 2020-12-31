//INNNNoVation!!!
class Solution {
public:
    string maximumBinaryString(string binary) {
        int n = binary.size();
        int num = 0, index = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (binary[i] == '0') num += 1, index = min(index, i);
        }
        string ans = "";
        if (index == INT_MAX)
        {
            for (int i = 0; i < n; i++) ans += '1';
        }
        else
        {
            for (int i = 0; i < index + num - 1; i++) ans += '1';
            ans += '0';
            for (int i = index + num; i < n; i++) ans += '1';
        }
        return ans;
    }
};