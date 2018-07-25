// #include <iostream>
// #include <iterator>
// #include <vector>
// #include <algorithm>
// #include <string>

// using namespace std;

// vector<vector<int> > adj;
// void makeGraph(const vector<string>& words) {
//     adj = vector<vector<int> >(26, vector<int>(26, 0));

//     for (int j = 1; j < words.size(); ++j) {
//         int i = j - 1;
//         int len = min(words[i].size(), words[j].size());

//         for (int k = 0; k < len; ++k) {
//             if (words[i][k] != words[j][k]) {
//                 int a = words[i][k] - 'a';
//                 int b = words[j][k] - 'a';
//                 adj[a][b] = 1;
//                 break;
//             }
//         }
//     }
// }

// vector<int> seen, order;
// void dfs(int here) {
//     seen[here] = 1;
//     for (int there = 0; there < adj.size(); ++there) {
//         if (adj[here][there] && !seen[there]) {
//             dfs(there);
//         }
//     }
//     order.push_back(here);
// }

// vector<int> topologicalSort() {
//     int n = adj.size();
//     seen = vector<int>(n, 0);
//     order.clear();

//     for (int i = 0; i < n; ++i) {
//         if (!seen[i]) {
//             dfs(i);
//         }
//     }
//     reverse(order.begin(), order.end());

//     for (int i = 0; i < n; ++i) {
//         for (int j = i + 1; j < n; ++j) {
//             if (adj[order[j]][order[i]]) {
//                 return vector<int>();
//             }
//         }
//     }

//     return order;
// }

// int main(void) {
//     int t;
//     cin >> t;
//     while (t--) {
//         int size;
//         cin >> size;
//         vector<string> words;
//         for (int i = 0; i < size; ++i) {
//             string word;
//             cin >> word;
//             words.push_back(word);
//         }

//         makeGraph(words);

//         auto ret = topologicalSort();
//         if (ret.empty()) {
//             cout << "INVALID HYPOTHESIS" << endl;
//             continue;
//         }

//         for_each(ret.begin(), ret.end(), [](int& ch) { ch = ch + 'a'; });
//         copy(ret.begin(), ret.end(), ostream_iterator<char>(cout));
//         cout << endl;
//     }

//     return 0;
// }

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int> > adj;
vector<int> seen, order;

void dfs(int here) {
    seen[here] = 1;

    for (int there = 0; there < adj.size(); ++there) {
        if (adj[here][there] == 1 && !seen[there]) {
            dfs(there);
        }
    }
    order.push_back(here);
}

vector<int> sort() {
    int n = adj.size();
    seen = vector<int>(n);
    order.clear();
    for (int i = 0; i < n; ++i) {
        if (!seen[i]) {
            dfs(i);
        }
    }

    reverse(order.begin(), order.end());

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (adj[order[j]][order[i]] == 1) {
                return vector<int>();
            }
        }
    }

    return order;
}
int main(void) {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;

    for (int _ = 0; _ < t; ++_) {
        adj = vector<vector<int> >(26, vector<int>(26, 0));

        int word_length;
        cin >> word_length;

        string word;
        cin >> word;
        for (int i = 1; i < word_length; ++i) {
            string nextWord;
            cin >> nextWord;

            int minlen = min(word.size(), nextWord.size());

            for (int j = 0; j < minlen; ++j) {
                if (word[j] != nextWord[j]) {
                    int from = word[j] - 'a';
                    int to = nextWord[j] - 'a';

                    adj[from][to] = 1;
                    break;
                }
            }

            word = nextWord;
        }

        vector<int> ans = sort();

        if (ans.empty()) {
            cout << "INVALID HYPOTHESIS" << endl;
            continue;
        } else {
            for_each(order.begin(), order.end(), [](int& ch) { cout << (char)(ch + 'a'); });
            cout << endl;
        }
    }

    return 0;
}
