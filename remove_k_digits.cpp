class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        for(char &ch:num){
            if(s.empty()||k==0)
                s.push(ch);
            else{
                
                while(!s.empty() && s.top()>ch && k>0)
                    s.pop(),k--;
                
                s.push(ch);
            }
        }
        while(k>0 && !s.empty())
            s.pop(),k--;
        string ans;
        while(!s.empty())
            ans+=s.top(),s.pop();
        reverse(ans.begin(),ans.end());
        int i=0;
        while(i<ans.length() && ans[i]=='0')
            i++;
        if(i==ans.length())
            return "0";
        else
            return ans.substr(i,ans.length());
        
    }
};