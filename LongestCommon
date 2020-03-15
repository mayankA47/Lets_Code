int dp[5555][5555];
int commonChild(string s1, string s2,int i=0,int j=0) {
    for(int i=0;i<s1.length()+1;i++){
        for(int j=0;j<s2.length()+1;j++){
            if(i==0||j==0)
            dp[i][j]=0;
            else if(s1[i-1]==s2[j-1])
            dp[i][j] = dp[i-1][j-1] + 1;
            else 
            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[s1.length()][s2.length()];
}
