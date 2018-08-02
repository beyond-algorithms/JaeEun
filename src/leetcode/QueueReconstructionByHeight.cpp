class Solution {
   public:
    struct CompareIndex {
        bool operator()(pair<int, int> n1, pair<int, int> n2) {
            return n1.second > n2.second;
        }
    };
    typedef priority_queue<pair<int, int>, vector<pair<int, int>>, CompareIndex> Q;

    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        if (people.empty()) {
            return vector<pair<int, int>>();
        }
        vector<pair<int, int>> res;
        int len = people.size() + 1000000;

        vector<Q> vec(len);
        for (auto person : people) {
            vec[person.first].push(person);
        }

        for (int i = len - 1; i >= 0; --i) {
            auto q = vec[i];
            while (!q.empty()) {
                res.insert(res.begin() + q.top().second, q.top());
                q.pop();
            }
        }

        return res;
    }
};
