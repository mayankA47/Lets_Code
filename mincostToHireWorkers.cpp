//leetcode #857 HARD
class Solution {
public:
    vector<pair<int,int>> cost;
    static bool mycompare(pair<int,int> &a,pair<int,int> &b){
        return (double)a.first/a.second > (double)b.first/b.second;
    }
    
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        for(int i=0;i<wage.size();i++)
            cost.push_back({wage[i],quality[i]});
        sort(cost.begin(),cost.end(),mycompare);
        double mincost = INT_MAX;
        priority_queue<int> pq;
        int sum = 0;
        for(int i=cost.size()-1;i>=0;i--){
            sum += cost[i].second;
            pq.push(cost[i].second);
            if(pq.size()>k)
                sum -= pq.top(), pq.pop();
            if(i<=cost.size()-k)
                mincost = min(mincost,(double)cost[i].first*sum/cost[i].second);
        }
           
        return mincost;
    }
};
