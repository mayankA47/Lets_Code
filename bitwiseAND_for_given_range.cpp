class Solution {
public:
     
    bool set_next(int m,int n,int bit){
        while(bit>=0 && (m>>bit)&1)
            bit--;
        bit++;
        long long cmp = m + (long long)(1<<bit);
        long long mask=0;
        for(int i=bit;i<32;i++)
            mask+=(1<<i);
        cmp = cmp&(mask);
        return cmp<=n;
    }
    int rangeBitwiseAnd(int m, int n) {
        int ans = 0;
        for(int i=0;i<32;i++){
            if((m>>i)&1){
                // to check existence of smallest m<x<=n whose ith bit is reset
                bool found = set_next(m,n,i);
                if(!found)
                    ans += (1<<i);
            }
        }
        return ans;
    }
};