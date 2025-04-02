/*
140. Word Break II
Solved
Hard
Topics
Companies
Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog","cat sand dog"]
Example 2:

Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
Explanation: Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: []
 

Constraints:

1 <= s.length <= 20
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 10
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.
Input is generated in a way that the length of the answer doesn't exceed 105.
*/
class Solution {
public:
    vector<int> computed;
    vector<vector<string>> dp;
    vector<string> wordBreakHelper(int idx, string &s, unordered_set<string> &dict) {
        if (idx == s.length())
            return {};
        if (computed[idx])
            return dp[idx];
        computed[idx] = 1;
        string cur;
        vector<string> ans;
        for (int i = idx; i < s.length(); i++) {
            cur += s[i];
            if (dict.find(cur) != dict.end()) {
                vector<string> curAns = wordBreakHelper(i+1, s, dict);
                if (curAns.size() > 0) {
                    for (string &locAns: curAns)
                        ans.push_back(cur + ' ' + locAns);
                } else if (i+1 == s.length())
                    ans.push_back(cur);
            }
        }
        return dp[idx] = ans;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        computed.resize(n, 0);
        dp.resize(n);
        unordered_set<string> dict;
        for (string &word: wordDict) {
            dict.insert(word);
        }
        return wordBreakHelper(0, s, dict);
    }
};
