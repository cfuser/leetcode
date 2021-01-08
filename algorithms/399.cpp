//INNNoVation!!!


/*
transfer /phi to /sigma /ln 
a good idea from heltion
helggnb!
*/

/*
dsu
*/

class Solution {
public:
    const int N = 40 + 5;
    struct Node
    {
        int p;
        int r;
        double value;
    };
    vector<Node> node = vector<Node>(N);
    
    int get(int x)
    {
        if (node[x].p == x) return x;
        int y = get(node[x].p);
        node[x].value = node[node[x].p].value + node[x].value;
        node[x].p = y;
        return node[x].p;
    }
    
    int _union(int x, int y, double z)
    {
        int xx = get(x), yy = get(y);
        if (xx == yy) return 0;
        if (node[xx].r == node[yy].r) node[xx].r++;
        z = z - node[x].value + node[y].value;
        if (node[xx].r > node[yy].r)
        {
            node[yy].p = xx;
            node[yy].value = -z;
        }
        else
        {
            node[xx].p = yy;
            node[xx].value = z;
        }
        return 0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int nvars = 0;
        unordered_map<string, int> variables;
        int n = equations.size();
        for (int i = 0; i < n; i++)
        {
            if (variables.find(equations[i][0]) == variables.end())
            {
                variables[equations[i][0]] = nvars;
                nvars++;
            }
            if (variables.find(equations[i][1]) == variables.end())
            {
                variables[equations[i][1]] = nvars;
                nvars++;
            }
        }

        for (int i = 0; i < nvars; i++)
        {
            node[i].p = i;
            node[i].r = 0;
            node[i].value = 0;
        }
        for (int i = 0; i < n; i++)
        {
            int x = variables[equations[i][0]], y = variables[equations[i][1]];
            double z = log(values[i]);
            _union(x, y, z);
        }
        


        vector<double> ans;
        int m = queries.size();
        for (int i = 0; i < m; i++)
        {
            double result = -1.0;
            if (variables.find(queries[i][0]) != variables.end() && variables.find(queries[i][1]) != variables.end())
            {
                int x = variables[queries[i][0]], y = variables[queries[i][1]];
                int xx = get(x), yy = get(y);
                if (xx == yy) result = exp(node[x].value - node[y].value);
            }
            ans.push_back(result);
        }
        return ans;
    }
};

/*
floyd
*/

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int nvars = 0;
        unordered_map<string, int> variables;
        int n = equations.size();
        for (int i = 0; i < n; i++)
        {
            if (variables.find(equations[i][0]) == variables.end())
            {
                variables[equations[i][0]] = nvars;
                nvars++;
            }
            if (variables.find(equations[i][1]) == variables.end())
            {
                variables[equations[i][1]] = nvars;
                nvars++;
            }
        }
        vector< vector<double>> dis(nvars, vector<double>(nvars, DBL_MIN));
        for (int i = 0; i < n; i++)
        {
            int x = variables[equations[i][0]], y = variables[equations[i][1]];
            dis[x][y] = log(values[i]);
            dis[y][x] = -dis[x][y];
        }
        for (int k = 0; k < nvars; k++)
            for (int i = 0; i < nvars; i++)
                for (int j = 0; j < nvars; j++)
                if (dis[i][k] != DBL_MIN && dis[k][j] != DBL_MIN)
                    dis[i][j] = dis[i][k] + dis[k][j];
        vector<double> ans;
        int m = queries.size();
        for (int i = 0; i < m; i++)
        {
            double result = -1.0;
            if (variables.find(queries[i][0]) != variables.end() && variables.find(queries[i][1]) != variables.end())
            {
                int x = variables[queries[i][0]], y = variables[queries[i][1]];
                if (dis[x][y] != DBL_MIN) result = exp(dis[x][y]);
            }
            ans.push_back(result);
        }
        return ans;
    }
};