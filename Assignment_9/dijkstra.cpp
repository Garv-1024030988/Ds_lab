class Solution {
  public:
  
    void add_edge(int src,int des,int w,vector<list<pair<int,int>>>&adj){
        adj[src].push_back({des,w});
        adj[des].push_back({src,w});
    }
    
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        vector<list<pair<int,int>>>adj(V,list<pair<int,int>>());
        
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            add_edge(u,v,w,adj);
        }
      
        vector<int>dis(V);
        for(int i=0;i<V;i++) dis[i]=1e6;
        
        dis[src]=0;
        pq.push({0,src});
        
        while(not pq.empty()){
            int distance=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            if(distance > dis[node]) continue;
            
            for(auto nbr:adj[node]){
                int nbrNode=nbr.first;
                int w=nbr.second;
                if(distance+w<dis[nbrNode]){
                    dis[nbrNode]=w+distance;
                    pq.push({dis[nbrNode],nbrNode});
                }
            }
        }
        return dis;
        
    }
};
