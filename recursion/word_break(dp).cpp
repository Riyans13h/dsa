/*
Problem: Word Break

Given a string `s` and a dictionary of strings `wordDict`, return true if `s` can be segmented 
into a space-separated sequence of one or more dictionary words.

Note:
- The same word in the dictionary may be reused multiple times in the segmentation.

Examples:

1. Input: s = "leetcode", wordDict = ["leet","code"]
   Output: true
   Explanation: "leetcode" can be segmented as "leet code".

2. Input: s = "applepenapple", wordDict = ["apple","pen"]
   Output: true
   Explanation: "applepenapple" can be segmented as "apple pen apple".

3. Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
   Output: false

Constraints:
- 1 <= s.length <= 300
- 1 <= wordDict.length <= 1000
- 1 <= wordDict[i].length <= 20
- s and wordDict[i] consist of only lowercase English letters.
- All strings in wordDict are unique.
*/

class Solution {
public:
    // Recursive helper with memoization to avoid recomputation
    bool solve(int index, set<string>& st, string& s, vector<int>& dp) {
        if (index == s.size()) return true;
        if (dp[index] != -1) return dp[index];

        string temp = "";
        for (int i = index; i < s.size(); i++) {
            temp.push_back(s[i]);
            if (st.find(temp) != st.end()) {
                if (solve(i + 1, st, s, dp)) {
                    return dp[index] = true;
                }
            }
        }

        return dp[index] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size(), -1);  // dp[i] stores whether s[i:] can be segmented
        return solve(0, st, s, dp);
    }
};
/// with dp ...
class Solution {
public:
   bool solve (  int index , set<string> &st, string s  ){
    if ( index == s.size()) return true;
    // for storing the word 
    string   temp =""; 
    for ( int i =index ;i<s.size() ; i++){
        temp.push_back(s[i]);
        if ( st.find(temp) != st.end()){
            // if  word found in the  dictionary 
           if ( solve(i+1 ,st , s )) return true;
           // back tracking 
          // temp.pop_back();
        }
    }
    return false ;

   }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st (wordDict.begin() , wordDict.end());
        if ( solve(0, st , s )) return true;
        return false ;
    }
};   // this is getting the timr limit exceeding 