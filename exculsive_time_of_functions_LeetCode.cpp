class Solution {
public:
    struct process{
        int id;
        int start;
        int time;
        process(int a,int b,int c){
            id=a;
            start=b;
            time=c;
        }
    };
    process decode(string &s){
        string tmp;
        int cnt = 0;
        int start;
        int id,time;
        for(int i=0;i<s.length();i++){
            if(s[i]==':' && cnt==1){
                if(s[i-1]=='t')
                  start=1;
                else
                    start=0;
                tmp.clear();
            }
            else if(s[i]==':'){
                
                    id = stoi(tmp);
                    cnt++;
                    tmp.clear();
            }
            else
                tmp+=s[i];
        }
        time = stoi(tmp);
        process p(id,start,time);
        return p;
    }
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<process> s;
        vector<int> ans(n,0);
        for(int i=0;i<logs.size();i++){
            process p = decode(logs[i]);
            if(p.start){
                s.push(p);
            }
            else{
                int process_time = (p.time-s.top().time+1);
                s.pop();
                ans[p.id] += process_time;
                //eating time of process its running on!
                if(!s.empty()){
                    ans[s.top().id] -= process_time;
                }
                   
            }
        }
        return ans;
        
    }
};