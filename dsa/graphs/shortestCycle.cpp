class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        /*
            With generic DFS/BFS, can determine cycle nut not shortest cycle with O(V+E) complexity,
            can do it with O(V*(V+E)).
            Example - n = 8, edges = [[0,1],[1,2],[2,3],[3,4],[4,5],[0,7],[0,6],[5,7],[5,6]]; 
            answer for above case is 4 (and not 7)
        */
        // return solveByDfs(n, edges);
        return solveByBFS(n, edges);
    }

    int solveByBFS(int n, vector<vector<int>> &edges) {
        vector<vector<int>> g(n);
        for (auto &edge : edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        int ans = INT_MAX;
        for (int cur = 0; cur < n; cur++) {
            queue<vector<int>> q; // {node, parent}
            vector<int> distance(n, -1);
            distance[cur] = 1;
        
            q.push({cur, cur});
            while(!q.empty()) {
                vector<int> present = q.front();
                q.pop();
                int node = present[0], parent = present[1];
                for (int &child: g[node]) {
                    if (child == parent)
                        continue;
                    else if (distance[child] != -1) {
                        ans = min(ans, distance[child] + distance[node] - 1);
                    }
                    else {
                        distance[child] = distance[node] + 1;
                        q.push({child, node});
                    }
                }
            }
        }
        return ans == INT_MAX ? -1: ans;
    }

    int getShortestCycle(int par, int cur, vector<vector<int>> &g, vector<int> &visited, int depth, vector<bool> &overallVisited) {
        int ans = INT_MAX;
        for (int &nbr: g[cur]) {
            if (nbr == par)
                continue;
            if (visited[nbr] != -1) {
                // cout << "Found cycle at "<< par << cur << nbr << endl;
                ans = min(ans, depth - visited[nbr] + 1);
                continue;
            }
            visited[nbr] = depth+1; 
            ans = min(ans, getShortestCycle(cur, nbr, g, visited, depth+1, overallVisited));
            visited[nbr] = -1;
        }
        overallVisited[cur] = true;
        return ans;
    }

    int solveByDfs(int n, vector<vector<int>> &edges) {
        vector<vector<int>> g(n);
        for (auto &edge : edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        vector<int> visited(n, -1); // stack
        vector<bool> overallVisited(n, false); // visited
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            if(!overallVisited[i])
                overallVisited[i] = true, visited[i] = 1, ans = min(ans, getShortestCycle(i, i, g, visited, 1, overallVisited)), visited[i] = -1;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};