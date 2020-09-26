/*
Given two arrays of integers with equal lengths, return the maximum value of:

|arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|

where the maximum is taken over all 0 <= i, j < arr1.length.

 

Example 1:

Input: arr1 = [1,2,3,4], arr2 = [-1,4,5,6]
Output: 13
Example 2:

Input: arr1 = [1,-2,-5,0,10], arr2 = [0,-2,-1,-7,-4]
Output: 20
 

Constraints:

2 <= arr1.length == arr2.length <= 40000
-10^6 <= arr1[i], arr2[i] <= 10^6
*/

class Solution {
public:
    void initialize(int &pp,int &pn, int &np, int &nn, vector<int>& arr1, vector<int>& arr2, int i){
        pp = arr1[i] + arr2[i] -i;
        pn = arr1[i] - arr2[i] -i;
        np = -arr1[i] + arr2[i] -i;
        nn = -arr1[i] - arr2[i] -i; 
    }
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int pp, pn, np, nn;
        initialize(pp,pn,np,nn,arr1,arr2,0);
        int ans = 0;
        for(int i=1; i<arr1.size(); i++){
            int ppd,pnd,npd,nnd;
            initialize(ppd,pnd,npd,nnd,arr1,arr2,i);
            ans = max(ans,2*i + max(ppd+nn,max(pnd+np,max(npd+pn,nnd+pp))));
            pp = max(pp,ppd);
            nn = max(nn,nnd);
            np = max(np,npd);
            pn = max(pn,pnd);
        }
        return ans;
    }
};
