vector<vector<int> > Solution::prettyPrint(int A) {
    if(A==1){
        vector<vector<int>> ans;
        vector<int> t;
        t.push_back(1);
        ans.push_back(t);
        return ans;
    }
    int n = 2*A-1;
    vector<vector<int>> ans(n,vector<int>(n,-1));
    int i,j;
    i = j = 0;
    int el = A;
    while(ans[i][j]==-1){
        int N = 2*el-1;
        for(int x=0;x<N;x++)
        ans[i+x][j] = el;
        for(int y=1;y<N;y++)
        ans[i+N-1][j+y] = el;
        for(int x=N-2;x>=0;x--)
        ans[i+x][j+N-1] = el;
        for(int y=N-2;y>=0;y--)
        ans[i][j+y] = el;
        i++;
        j++;
        el--;
        
    }
    return ans;
}
