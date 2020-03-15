// Complete the evenForest function below.
int ans;
unordered_map<int,vector<int> >m;
unordered_map<int,bool> v;
int countnodes(vector<int> &count,int cnode){
    v[cnode]=1;
    for(auto i:m[cnode]){
        if(!v[i]){
            int q = countnodes(count,i);
            count[cnode]+=q;
        }
    }
    return count[cnode];
}
int evenForest(int t_nodes, int t_edges, vector<int> t_from, vector<int> t_to) {
ans=0;
m.clear();
v.clear();
for(int i=0;i<t_edges;i++){
    m[t_from[i]].push_back(t_to[i]);
    m[t_to[i]].push_back(t_from[i]);
}
vector<int> count(t_nodes+1,1);
int q=countnodes(count,1);
for(int i=0;i<count.size();i++){
    cout<<count[i]<<",";
    if(count[i]!=0 && count[i]%2==0)
    ans++;

}
return ans-1;


}