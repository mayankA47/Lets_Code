class Solution {
public:
/*
1. iterating over each cell as start

    find number of increasing paths
    x-y such that val(x) < val (y)
    ans(x) with y as second cell = ans(y)

    algorithm -> 1. end here
    2. try moving in all 4 directions 

    maintain a stack for tracking visited cells in a path - no need!!, reasons - 
    1. strictly inc means a cell in a path can never be crossed again!
    2. if stack is added, memoization would make no sense.


*/
    int m = 1e9 + 7;
    int add (int a, int b) {
        return (a%m + b%m)%m;
    }
    vector<vector<int>> dp;
    int getIncreasingPaths(vector<vector<int>> &grid, int x, int y) {
        if (dp[x][y] != -1)
            return dp[x][y];

        int ans = 1; // end here itself

        vector<int> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];

            if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[x][y] < grid[nx][ny])
                ans = add(ans, getIncreasingPaths(grid, nx, ny));
        }

        return dp[x][y] = ans;
    }

    int countPaths(vector<vector<int>>& grid) {
        dp.resize(grid.size());
        for(int i = 0; i < grid.size(); i++)
            dp[i].resize(grid[0].size(), -1);

        int ans = 0;


        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                ans = add(ans, getIncreasingPaths(grid, row, col));
            }
        }

        return ans;
    }
};