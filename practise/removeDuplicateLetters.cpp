/*
Given a string which contains only lowercase letters, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Example 1:

Input: "bcabc"
Output: "abc"
Example 2:

Input: "cbacdcbc"
Output: "acdb"
*/
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int f[26] = {0};
        for(char &ch:s){
            f[ch-'a']++;
        }
        string ans;
        stack<char> st;
        bool vis[26] = {0};
        for(int i=0;i<s.length();i++){
            if(vis[s[i]-'a']==1){
                f[s[i]-'a']--;
                continue;
            }
            while(!st.empty() && st.top()>s[i] && f[st.top()-'a']>0)
                vis[st.top()-'a']=0, st.pop();
            st.push(s[i]);
            vis[s[i]-'a']=1, f[s[i]-'a']--;
                
        }
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
