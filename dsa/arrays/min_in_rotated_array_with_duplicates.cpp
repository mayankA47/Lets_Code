/*
154. Find Minimum in Rotated Sorted Array II
Solved
Hard
Topics
Companies
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,4,4,5,6,7] might become:

[4,5,6,7,0,1,4] if it was rotated 4 times.
[0,1,4,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums that may contain duplicates, return the minimum element of this array.

You must decrease the overall operation steps as much as possible.

 

Example 1:

Input: nums = [1,3,5]
Output: 1
Example 2:

Input: nums = [2,2,2,0,1]
Output: 0
 

Constraints:

n == nums.length
1 <= n <= 5000
-5000 <= nums[i] <= 5000
nums is sorted and rotated between 1 and n times.

*/
class Solution {
public:
    bool isStart(int idx, vector<int> &a) {
        if (idx-1 >= 0 && idx+1 < a.size())
            return a[idx] < a[idx-1] && a[idx+1] > a[idx];
        else if (idx-1 >= 0)
            return a[idx] < a[idx-1];
        // can't confirm confidently about other cases
        return false;
    }
    int findMin(vector<int>& nums) {
        int last = nums[nums.size()-1];
        int lo = 0, hi = nums.size()-1, mid;
        int ans = nums[lo];
        while (lo <= hi) {
            mid = (hi-lo)/2 + lo;
            if (isStart(mid, nums)) 
                return nums[mid];
            else {
                if (nums[lo] <= nums[mid] && nums[mid] <= nums[hi]) // [2 2 2 1 2]
                    ans = min(ans, nums[lo]), lo++, hi--;
                // only left half sorted - ans is nums[lo] or can lie in right half
                else if (nums[lo] <= nums[mid])
                    ans = min(ans, nums[lo]), lo = mid+1;
                // only right half sorted - ans is nums[mid] or can lie in left half
                else if(nums[mid] <= nums[hi])
                    ans = min(ans, nums[mid]), hi = mid-1;
            } 
        }
        return ans;
    }
};
