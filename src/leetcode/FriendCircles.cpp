class Solution {
   public:
    vector<bool> visited;
    
    int dfs(vector<vector<int>>& M, int here) {
        if (visited[here]) {
            return 0;
        }

        visited[here] = true;
        for (int there = 0; there < M.size(); ++there) {
            if (M[here][there] && !visited[there]) {
                dfs(M, there);
            }
        }
        return 1;
    }
    int findCircleNum(vector<vector<int>>& M) {
        int ret = 0;
        visited.resize(M.size(), false);

        for (int i = 0; i < M.size(); ++i) {
            ret += dfs(M, i);
        }

        return ret;
    }
};

static const auto ______ = []() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

//Union Find
class Solution {
   public:
    int findCircleNum(vector<vector<int>>& M) {
        if (M.empty()) return 0;
        int n = M.size();

        vector<int> leads(n, 0);
        for (int i = 0; i < n; i++) {
            leads[i] = i;
        }  // initialize leads for every kid as themselves

        int groups = n;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {  // avoid recalculate M[i][j], M[j][i]
                if (M[i][j]) {
                    int lead1 = find(i, leads);
                    int lead2 = find(j, leads);
                    if (lead1 != lead2) {  // if 2 group belongs 2 different leads, merge 2 group to 1
                        leads[lead1] = lead2;
                        groups--;
                    }
                }
            }
        }
        return groups;
    }

   private:
    int find(int x, vector<int>& parents) {
        return parents[x] == x ? x : find(parents[x], parents);
    }
};