class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> d;
        //int last = nums[0];
        vector<int> ans;
        if(nums.size()==0){
          //  ans.push_back(0);
            return ans;
        }
        d.push_back(0);
        for(int i=1;i<k;i++){
            if(nums[i]>nums[d.back()]){
                while(!d.empty()){
                    if(nums[i]>nums[d.back()])
                        d.pop_back();
                    else
                        break;
                }
               
            }
             d.push_back(i);
        }
        ans.push_back(nums[d.front()]);
        for(int i=k;i<nums.size();i++){
            //delete previous elemnts
            while(i-k>=d.front() && !d.empty()){
                d.pop_front();
            }
            //remove all previous elemnts with lesser index having smaller value than current
             if(nums[i]>nums[d.back()]){
                while(!d.empty()){
                    if(nums[i]>nums[d.back()])
                        d.pop_back();
                    else
                        break;
                }
               
            }
             d.push_back(i);
            //front indexed element is the answer for current window 
            ans.push_back(nums[d.front()]);
            
        }
        return ans;
    }
};