class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        for(auto i: prerequisites) {
            adj[i[1]].push_back(i[0]);
        }
        vector<int> topo;
        vector<int> indeg(n, 0);
        for(int i=0; i<n; i++) {
            for(auto it: adj[i]) indeg[it]++;
        }
        queue<int> q;
        for(int i=0; i<n; i++) {
            if(indeg[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it: adj[node]) {
                indeg[it]--;
                if(indeg[it] == 0) q.push(it);
            }
        }
        return (topo.size() == n);
    }
};