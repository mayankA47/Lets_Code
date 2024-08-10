class Solution {
public:
    // basically is it possible to color a graph using 2 colors
    // such that no two adjacent nodes have same color

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);
        
        for (int node = 0; node < graph.size(); node++) {
            if (color[node] != -1)
                continue;
            
            queue<int> q;
            q.push(node);
            color[node] = 0;   
            while (!q.empty()) {
                int curNode = q.front();
                q.pop();
                
                for (int &child: graph[curNode]) {
                    if (color[child] == -1) {
                        color[child] = color[curNode] ^ 1;
                        q.push(child);
                    } else if (color[child] != color[curNode] ^ 1)
                        return false;
                }
            }
        }
        
        return true;
    }
};