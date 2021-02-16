// Question Link: https://leetcode.com/problems/word-ladder

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(begin(wordList), end(wordList)), seen;
        // If endWord is not in the list, we cannot reach to the end
        if (words.find(endWord) == words.end()) {
            return 0;
        }
        queue<pair<string, int>> todo; // {word, step}
        todo.push({beginWord, 1});
        while (!todo.empty()) {
            pair<string, int> cur = todo.front();
            todo.pop();
            if (cur.first == endWord) {
                return cur.second;
            }
            // Get the all transformations can be formed from cur word, then check
            // If they are in the word list
            for (int c = 0; c < cur.first.size(); c++) {
                string up = cur.first, down = cur.first;
                while (islower(++up[c])) {
                    if (words.find(up) != words.end() && seen.find(up) == words.end()) {
                        todo.push({up, cur.second + 1});
                        seen.insert(up);
                    }
                }
                while (islower(--down[c])) {
                    if (words.find(down) != words.end() && seen.find(down) == words.end()) {
                        todo.push({down, cur.second + 1});
                        seen.insert(down);
                    }
                }
            }
        }
        return 0;
    }
};