class Solution {
public:
    string shortestCommonSupersequence(string a, string b) {
        int i,j,k,n=a.length(),m=b.length();
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if(a[i-1]==b[j-1]) dp[i][j]= dp[i-1][j-1] + 1;
                else dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
            }
        }
        i=n;j=m;
        string ans= "";
        while(i>0 && j>0)
        {
            if(a[i-1]==b[j-1]){
                ans+= a[i-1];
                i--;j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                ans+= a[i-1];
                i--;
            }
            else{
                ans+= b[j-1];
                j--;
            }
        }
        while(i>0){
            ans+= a[i-1];
            i--;
        }
        while(j>0){
            ans+= b[j-1];
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
