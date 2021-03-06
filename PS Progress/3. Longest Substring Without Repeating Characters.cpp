// Question Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0, L = 0, size = s.size(), setLen;
        if (size <= 1) {
            return size;
        }
        unordered_set<char> letterSet = { s[0] };
        for (int R = 1; R < size; R++) {
            if (letterSet.find(s[R]) == letterSet.end()) {
                letterSet.insert(s[R]);
            }
            else {
                for (; s[L] != s[R]; L++) {
                    letterSet.erase(s[L]);
                };
                L++;
            }
            setLen = letterSet.size();
            maxLen = max(maxLen, setLen);
        }
        return maxLen;
    }
};
