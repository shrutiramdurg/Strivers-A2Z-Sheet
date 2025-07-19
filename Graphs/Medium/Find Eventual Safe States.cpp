class Solution {
public:
    int n;
    vector<int> indegree;
    vector<vector<int>> revgraph;
    vector<int> ans;

    void init(vector<vector<int>>& G){
        n = G.size();
        indegree = vector<int>(n,0);
        revgraph.resize(n, vector<int>(0) );
        
        for (int u=0; u<n; u++){
            for (int v:G[u]){
                revgraph[v].push_back(u);
                indegree[u]++;
            }
        }
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        init(graph);
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int u = q.front(); q.pop();
            ans.push_back(u);
            for(int v : revgraph[u]){
                indegree[v]--;
                if(indegree[v] == 0) q.push(v);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};