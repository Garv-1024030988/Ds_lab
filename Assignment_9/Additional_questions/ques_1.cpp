class Solution {
public:
    int countComponents(int V, vector<vector<int>>& edges) {

        vector<vector<int>> g(V);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<bool> vis(V, false);
        queue<int> q;
        int ans = 0;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                ans++;

                q.push(i);
                vis[i] = true;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int nei : g[node]) {
                        if (!vis[nei]) {
                            vis[nei] = true;
                            q.push(nei);
                        }
                    }
                }
            }
        }

        return ans;
    }
};
