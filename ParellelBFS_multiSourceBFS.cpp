/*link to problem statement:https://www.hackerrank.com/
challenges/find-the-nearest-clone/problem?h_l=interview&playlist_slugs%5B%5D=
interview-preparation-kit&playlist_slugs%5B%5D=graphs*/
int findShortest(int graph_nodes, vector<int> graph_from, vector<int> graph_to, vector<long> ids, int val) {
    // solve here
    unordered_map<int,vector<int> >m;
    unordered_map<int,int> vid; //marks the visit ID
   unordered_map<int,int >dist;
    for(int i=0;i<graph_from.size();i++){
        int x= graph_from[i];
        int y= graph_to[i];
        m[x].push_back(y);
        m[y].push_back(x);
    }
    queue<int> q;
    for(int i=0;i<ids.size();i++){
        if(ids[i]==val)
        q.push(i+1),vid[i+1]=i+1,dist[i+1]=0;
    }
    if(q.size()<2)
    return -1;
    q.push(-1);
    int cur=1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        if(node==-1){
            if(!q.empty())
            q.push(-1);
            cur++;
        }
        else{
            //v[node]=;
            for(auto i:m[node]){
                if(!vid[i]){
                    q.push(i);
                    vid[i]=vid[node];
                    dist[i]=cur;
                }
                else if(vid[i]!=vid[node]){
                  return dist[i]+cur;
                 //   else 
                }
            }
        }
    }
    return -1;
}