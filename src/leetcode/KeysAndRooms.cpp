#include <unordered_set>

class Solution {
public:
    unordered_set<int> key;
    unordered_set<int> visited;
    
    bool canVisitAllRooms(vector<vector<int> >& rooms) {
        key.insert(0);
        doVisit(rooms, 0);
        
        return key.size() == rooms.size();
    }
    
    void doVisit(vector<vector<int> >& rooms, int num) {
        if (key.find(num) == key.end()) {
            return;
        }
        if (visited.find(num) != visited.end()) {
            return;
        }
        
        auto room = rooms.at(num);
        visited.insert(num);
        
        for (int num : room) {
            key.insert(num);
            doVisit(rooms, num);
        }
    }
    
};