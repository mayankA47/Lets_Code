class Solution {
public:
    /*
    high --> 1 --> goto X^1
             0 --> add freq(X^1), goto X^0
         
     low --> 1 --> add freq(X^0), goto X^1
            0 --> goto X^0
    */
    class node{
        public:
        int freq;
        node* kid[2];
        node(){
            freq = 1;
            kid[0] = kid[1] = NULL;
        }
    };
    class trie{
        node *root;
        public:
        trie(){
            root = new node();
        }
        void insert(int num){
            node* traveller = root;
            for(int bit=16; bit>=0 ;bit--){
                int curbit = 1&(num>>bit);
                if(traveller->kid[curbit])
                    traveller = traveller->kid[curbit], traveller->freq += 1;
                else{
                    traveller->kid[curbit] = new node();
                    traveller = traveller->kid[curbit];
                }
            }
        }
        int getSmall(int num, int low){
            node *traveller = root;
            int bit = 16, ans = 0;
            while(traveller && bit >= 0){
                int curbitlow = 1&(low>>bit), curbitnum = 1&(num>>bit);
                if(curbitlow){
                    if(traveller->kid[curbitnum^0])
                        ans += traveller->kid[curbitnum^0]->freq;
                    traveller = traveller->kid[curbitnum^1];
                }
                else{
                    traveller = traveller->kid[curbitnum^0];
                }
                bit--;
            }
            return ans;
        }
        int getLarge(int num, int high){
            node *traveller = root;
            int bit = 16, ans = 0;
            while(traveller && bit >= 0){
                int curbithigh = 1&(high>>bit), curbitnum = 1&(num>>bit);
                if(curbithigh == 0){
                    if(traveller->kid[curbitnum^1])
                        ans += traveller->kid[curbitnum^1]->freq;
                    traveller = traveller->kid[curbitnum^0];
                }
                else{
                    traveller = traveller->kid[curbitnum^1];
                }
                bit--;
            }
            return ans;
        }
        
    };
    int countPairs(vector<int>& nums, int low, int high) {
        int pairs = 0;
        trie T;
        for(int i=0; i<nums.size(); i++){
            pairs += i - (T.getSmall(nums[i], low) + T.getLarge(nums[i], high));
            T.insert(nums[i]);
        }
        return pairs;
    }
};
