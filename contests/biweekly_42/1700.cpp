//INNNNoVation!!!
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        queue<int> q;
        for (int i = 0; i < n; i++) q.push(students[i]);
        for (int i = 0; i < n; i++)
        {
            int j = q.size();
            while (q.front() != sandwiches[i])
            {
                j--;
                if (j == -1) break;
                q.push(q.front());
                q.pop();
            }
            if (j == -1) return q.size();
            q.pop();
        }
        return 0;
    }
};