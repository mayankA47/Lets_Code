
int Solution::numRange(vector<int> &A, int B, int C) {
    vector<long long> v;
    v.push_back(0);
    long long ans = 0;
    long long sum = 0;
    for(int i=0;i<A.size();i++){
        sum += A[i];
        long long l,h;
        h = sum-B;
        l = sum-C;
        auto it1 = upper_bound(v.begin(),v.end(),h);
        auto it2 = lower_bound(v.begin(),v.end(),l);
       
        int len = it1-it2;
        ans += len>0?len:0;
        v.push_back(sum);
    }
    return ans;
}
