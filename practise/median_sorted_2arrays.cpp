class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        //edge cases - if one of the array is empty
        if(n==0){
            if(m%2)
                return nums2[m/2];
            return (double)(nums2[m/2-1]+nums2[m/2])/2;
        }
        else if(m==0){
            if(n%2)
                return nums1[n/2];
            return (double)(nums1[n/2-1]+nums1[n/2])/2;
        }
        //leftel is total elements in left(smaller) pool
        int leftel = (m+n+1)/2;
        int start = 0;
        int end = n;
        while(start<=end){
            int partition1 = (start+end)/2;
            int partition2 = leftel - partition1;
            
            if(partition2<0)
            {
                //taking more elements fron nums1
                end = partition1-1;
                continue;
            }
            if(partition2>m){
                //taking less elements from nums1
                start = partition1+1;
                continue;
            }
            
            bool ok=1;
            if(partition1-1>=0 && partition2<m && nums1[partition1-1]>nums2[partition2])
                ok=0,end=partition1-1;
            if(partition1<n && partition2-1>=0 && nums1[partition1]<nums2[partition2-1])
                ok=0,start=partition1+1;
            if(ok){
                double el1 = partition1-1>=0?nums1[partition1-1]:INT_MIN;
                double el2 = partition2-1>=0?nums2[partition2-1]:INT_MIN;
                double el3 = partition1<n?nums1[partition1]:INT_MAX;
                double el4 = partition2<m?nums2[partition2]:INT_MAX;
                
               if((m+n)%2) 
                   return max(el1,el2);
                return (max(el1,el2)+min(el3,el4))/2;
            }
        }
        return 0;
    }
};
