class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;
    int count;
    MedianFinder() {
     /*   maxheap.clear();
        minheap.clear();*/
        count=0;
    }
    
    void addNum(int num) {
       maxheap.push(num);
        if(maxheap.size()-minheap.size()>1)
        {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        if(!minheap.empty()){
            if(minheap.top()<maxheap.top()){
                int temp = minheap.top();
                minheap.pop();
                minheap.push(maxheap.top());
                maxheap.pop();
                maxheap.push(temp);
            }
        }
        count++;
    }
    
    double findMedian() {
        double ans = maxheap.top();
        if(count%2==0)
            ans += minheap.top(),ans=(double)ans/2;
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */