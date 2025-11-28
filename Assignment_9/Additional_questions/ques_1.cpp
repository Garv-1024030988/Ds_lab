class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));
        int ans = 0;
        queue<pair<int, int>> q;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (not vis[i][j] && grid[i][j] == '1')
                {
                    ans++;
                    q.push({i, j});
                    vis[i][j]=true;
                    while (not q.empty())
                    {
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();
                        if ((r + 1) < grid.size() && grid[r + 1][c] == '1')
                        {
                            if (!vis[r+1][c])
                            {
                                q.push({r + 1, c});
                                vis[r+1][c]=true;
                            }
                        }
                        if ((c + 1) < grid[0].size() && grid[r][c + 1] == '1')
                        {
                            if (!vis[r][c+1])
                            {
                                q.push({r, c + 1});
                                vis[r][c+1]=true;
                            }
                        }
                        if ((r - 1) >= 0 && grid[r - 1][c] == '1')
                        {
                            if (!vis[r-1][c])
                            {
                                q.push({r - 1, c});
                                vis[r-1][c]=true;
                            }
                        }
                        if ((c - 1) >= 0 && grid[r][c - 1] == '1')
                        {
                            if (!vis[r][c-1])
                            {
                                q.push({r, c - 1});
                                vis[r][c-1]=true;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
