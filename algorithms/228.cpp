//INNNoVation!!!

/*
str.append()
*/
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;
        for (int i = 0; i < n; i++)
        {
            int j = i;
            while (j + 1 < n && nums[j + 1] == nums[j] + 1) j++;
            string str = "";
            str.append(to_string(nums[i]));
            if (i != j)
            {
                str.append("->");
                str.append(to_string(nums[j]));
            }
            ans.push_back(str);
            i = j;
        }
        return ans;
    }
};