/*
480. Sliding Window Median
Solved
Hard
Topics
premium lock icon
Companies
Hint
The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle values.

For examples, if arr = [2,3,4], the median is 3.
For examples, if arr = [1,2,3,4], the median is (2 + 3) / 2 = 2.5.
You are given an integer array nums and an integer k. There is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the median array for each window in the original array. Answers within 10-5 of the actual value will be accepted.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [1.00000,-1.00000,-1.00000,3.00000,5.00000,6.00000]
Explanation: 
Window position                Median
---------------                -----
[1  3  -1] -3  5  3  6  7        1
 1 [3  -1  -3] 5  3  6  7       -1
 1  3 [-1  -3  5] 3  6  7       -1
 1  3  -1 [-3  5  3] 6  7        3
 1  3  -1  -3 [5  3  6] 7        5
 1  3  -1  -3  5 [3  6  7]       6
Example 2:

Input: nums = [1,2,3,4,2,3,1,4,2], k = 3
Output: [2.00000,3.00000,3.00000,3.00000,2.00000,3.00000,2.00000]
 

Constraints:

1 <= k <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
*/

class Solution {
public:
/*
maintain two heaps, now as sliding window moves, we need to omit elements. They can be removed immediately if they're on top of heap, otherwise they can be maintained to be deleted lazily when they appear on top.
One more thing is we know in which heap would the ommited element may lie, maintain a wasted capacity holder for each heap. 
*/
    multiset<pair<int, int>> obsolete; // {element, heap (to which element belongs)}
    void insertAndRemoveElement(priority_queue<int> &mxHeap, priority_queue<int, vector<int>, greater<int>> &mnHeap, int &wastedMx, int &wastedMn, int add, int remove, int k) {
        if (mxHeap.top() >= remove)
            wastedMx++, obsolete.insert({remove, 0});
        else
            wastedMn++, obsolete.insert({remove, 1});

        // add the element
        if (mxHeap.top() >= add)
            mxHeap.push(add);
        else 
            mnHeap.push(add);

        // balance the heaps
        rebalance:
        while (mxHeap.size() - wastedMx > (k+1)/2) {
            if (obsolete.find({mxHeap.top(),0}) != obsolete.end()) {
                obsolete.erase(obsolete.find({mxHeap.top(),0}));
                mxHeap.pop();
                wastedMx--;
                continue;
            }
            mnHeap.push(mxHeap.top());
            mxHeap.pop();
        }

        while (mnHeap.size() - wastedMn > k/2) {
            if (obsolete.find({mnHeap.top(),1}) != obsolete.end()) {
                obsolete.erase(obsolete.find({mnHeap.top(),1}));
                mnHeap.pop();
                wastedMn--;
                continue;
            }
            mxHeap.push(mnHeap.top());
            mnHeap.pop();
        }

        // remove obsoletes from tops
        while (!mxHeap.empty() && obsolete.find({mxHeap.top(),0}) != obsolete.end()) {
            obsolete.erase(obsolete.find({mxHeap.top(),0}));
            mxHeap.pop();
            wastedMx--;
        }
        while (!mnHeap.empty() && obsolete.find({mnHeap.top(),1}) != obsolete.end()) {
            obsolete.erase(obsolete.find({mnHeap.top(),1}));
            mnHeap.pop();
            wastedMn--;
        }

        if (mnHeap.size() - wastedMn < k/2 || mxHeap.size() - wastedMx < (k+1)/2)
            goto rebalance;

    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int> mxHeap;
        priority_queue<int, vector<int>, greater<int>> mnHeap;
        int wastedMx = 0, wastedMn = 0;
        vector<double> medians;

        for(int i=0; i<nums.size(); i++) {
            if (i < k) {
                mxHeap.push(nums[i]);
                if (mxHeap.size() > (k+1)/2) {
                    mnHeap.push(mxHeap.top());
                    mxHeap.pop();
                }
            }
            else {
                insertAndRemoveElement(mxHeap, mnHeap, wastedMx, wastedMn, nums[i], nums[i-k], k);
            }

            if (i >= k-1) {
                double median = k%2 ? mxHeap.top() : (double)((double)mxHeap.top() + (double)mnHeap.top())/(2.00000);
                medians.push_back(median);
            }
        }
        return medians;
    }
};
