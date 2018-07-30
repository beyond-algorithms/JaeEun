class Solution {
   public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        unordered_set<string> built;
        string res;
        for (string w : words) {
            if (w.size() == 1 || built.count(w.substr(0, w.size() - 1))) {
                res = w.size() > res.size() ? w : res;
                built.insert(w);
            }
        }
        return res;
    }
};

class Solution {
   public:
    struct TrieNode {
        TrieNode* arr[26];
        bool eow;
    };

    TrieNode* getNode() {
        TrieNode* node = new TrieNode;
        for (int i = 0; i < 26; i++)
            node->arr[i] = NULL;
        node->eow = false;

        return node;
    }

    TrieNode* root;

    Solution() {
        root = getNode();
    }

    void insert(string word) {
        TrieNode* temp = root;
        for (auto w : word) {
            int index = w - 'a';
            if (temp->arr[index] == NULL)
                temp->arr[index] = getNode();
            temp = temp->arr[index];
        }
        temp->eow = true;
    }

    string search() {
        string ans = "";
        int maxvalue = 0;
        spsearch(root, 0, "", maxvalue, ans);

        return ans;
    }

    void spsearch(TrieNode* r, int curr, string currstr, int& max, string& ans) {
        TrieNode* temp = r;

        //For each node check all alphabets from a-z (Since lexico)
        for (int i = 0; i < 26; i++) {
            if (temp->arr[i] == NULL)
                continue;

            if (temp->arr[i]->eow) {
                curr++;
                currstr += (char)(i + 'a');

                ans = curr > max ? currstr : ans;
                max = curr > max ? curr : max;

                spsearch(temp->arr[i], curr, currstr, max, ans);

                curr--;
                currstr.pop_back();
            }
        }
    }

    string longestWord(vector<string>& words) {
        for (auto word : words)
            insert(word);

        string result = search();

        return result;
    }
};