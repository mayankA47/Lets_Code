class Solution {
public:
/*
    Greedy approach, make jump to next index such that
    reach is maximised, it's always best to jump to such index 
    as it opens up most options for further next jump!
*/
    int minJumps(vector<int> &arr) {
        int jumps = 0;
        int ptr = 0, reach = arr[0], idx = 0, nextJump;

        while(idx < arr.size()-1) {
            // can reach end now?
            if (reach >= arr.size()-1){
                jumps++;
                break;
            }

            // else evaluate next jump
            for (; ptr <= min(idx + arr[idx], (int)arr.size() - 1); ptr++)
                if (reach <= ptr + arr[ptr]) {
                    reach = ptr + arr[ptr];
                    nextJump = ptr;
                }

            // make the jump
            jumps++;
            idx = nextJump;
        }

        return jumps;
    }
    int jump(vector<int>& nums) {
        return minJumps(nums);
    }
};