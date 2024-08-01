class Solution {
public:
/*
    find farthest node distance for all nodes in the trees.
    For merge, take minimum of above value in both trees, resultant distance is min(tree1) + min(tree2) + 1
    answer = max(diameter of tree 1, diameter of tree 2,  min(tree1) + min(tree2) + 1)

    optimisation - no need to find the min(tree), just find the diameter and min(tree) is radius = (diameter+1)/2.

    for find farthest node distance for all nodes in the trees -
        DFS (depth, node, parent)
            ans = max(depth, DFS(depth+1, child, node))


*/
    vector<vector<int>> distances;

    vector<vector<int>> getAdjacencyList(vector<vector<int>> &edges) {
        vector<vector<int>> g(edges.size()+1);

        for(auto &edge : edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }

        return g;
    }

    int findDistances(vector<vector<int>> &g, int node, int par, int dist, int id) {
        int ans = dist;
        int maxChild = dist;

        for (int &child: g[node]) {
            if (child == par)
                continue;
            maxChild = findDistances(g, child, node, dist+1, id);
            ans = max(ans, maxChild - dist);
        }
        distances[id][node] = ans;
        return max(ans, maxChild);
    }

    int getMax(vector<int> &a) {
        if (a.size() == 0)
            return 0;
        int maxi = a[0];
        for (int &i: a)
            maxi = max(maxi, i);

        return maxi;
    }

    int getMin(vector<int> &a) {
        if (a.size() == 0)
            return 0;
        int max = a[0];
        for (int &i: a)
            max = min(max, i);

        return max;
    }

    int getLeafNode(vector<vector<int>> &g){
        for (int i = 0; i < g.size(); i++)
            if (g[i].size() == 1)
                return i;
        return 0;
    }

    int findDiameter(vector<vector<int>> &g) {
        // find farthest node from 0
        queue<pair<int, int>> q;
        q.push({0, 0});

        vector<int> dist(g.size(), INT_MAX);
        dist[0] = 0;
        int farthest = 0;
        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();

            for(int &child: g[cur.first]) {
                if (dist[child] > cur.second + 1) {
                    dist[child] = cur.second + 1;
                    q.push({child, cur.second + 1});
                    // trying to get farthest node
                    farthest = child;
                }
            }
        }

        // now again do a BFS starting from this farthest node to find diameter
        fill(dist.begin(), dist.end(), INT_MAX);
        dist[farthest] = 0;
        q.push({farthest, 0});

         while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();

            for(int &child: g[cur.first]) {
                if (dist[child] > cur.second + 1) {
                    dist[child] = cur.second + 1;
                    q.push({child, cur.second + 1});
                    // trying to get farthest distance
                    farthest = cur.second + 1;
                }
            }
        }
        cout<<farthest<<endl;
        return farthest;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        distances.resize(2);
        distances[0].resize(edges1.size()+1, 0);
        distances[1].resize(edges2.size()+1, 0);

        vector<vector<int>> g1 = getAdjacencyList(edges1), g2 = getAdjacencyList(edges2);
        int d1 = findDiameter(g1), d2 = findDiameter(g2);

        return max(d1, max(d2, (d1+1)/2 + (d2+1)/2 + 1));
    }
};