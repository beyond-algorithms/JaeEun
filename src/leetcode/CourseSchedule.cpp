#include <map>

class Solution {
    
public:
    vector<int> order;
    vector<bool> seen;
    
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (prerequisites.empty()) {
            return true;
        }
        
        auto graph = make_graph(numCourses, prerequisites);
        vector<bool> onpath(numCourses, false), visited(numCourses, false);
        
        seen = vector<bool>(numCourses, false);
        order = vector<int>();
        
        for (int i = 0; i < numCourses; ++i) {
            if (!seen[i]) {
                dfs(i, graph);
            }
        }
        
        reverse(order.begin(), order.end());
        for (int i = 0; i < order.size(); ++i) {
            cout << order[i] << " ";
        }
        
        return !isCycleIn(order, graph);
//         for (int i = 0; i < numCourses; ++i) {
//             if (!visited[i] && isCycleIn(graph, i, onpath, visited)) {
//                 return false;
//             }
//         }
//         return true;
    }
    
private:
    vector<unordered_set<int>> make_graph(int num, vector<pair<int, int>>& pres) {
        vector<unordered_set<int>> graph(num);
        
        for (auto pre : pres) {
            graph[pre.second].insert(pre.first);
            // cout << pre.second << "->" << pre.first << endl;
        }
        
        return graph;
    }
    
    void dfs(int here, vector<unordered_set<int>>& graph) {
        // cout << "d" << here << " " << endl;
        seen[here] = true;
        auto neigh = graph[here];
        
        for (int there = 0; there < seen.size(); ++there) {
            if (!seen[there] && neigh.count(there)) {
                dfs(there, graph);
            }
        }
        
        order.push_back(here);
    }
    
    bool isCycleIn(const vector<int>& order, vector<unordered_set<int>>& graph) {
        int len = order.size();
        
        for (int i = 0; i < len; ++i) {
            for (int j = i+1; j < len; ++j) {
                int from = order[i];
                int to = order[j];
                // cout << "should fail: " << to << "->" << from << " : " << graph[to].count(from) << endl;
                if (graph[to].count(from)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool isCycleIn(vector<unordered_set<int>>& graph, int here, vector<bool>& onpath, vector<bool>& visited) {
        if (visited[here]) return false;
        
        onpath[here] = visited[here] = true;
        
        for (int neigh : graph[here]) {
            if (onpath[neigh] || isCycleIn(graph, neigh, onpath, visited)) {
                return true;
            }
        }
        
        return onpath[here] = false;
    }
    
    
    
};