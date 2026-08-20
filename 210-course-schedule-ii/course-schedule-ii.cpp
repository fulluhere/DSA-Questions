class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();

        vector<vector<int>>adj(numCourses);
        vector<int>idg(numCourses);
        for(auto &it: prerequisites){
            adj[it[1]].push_back(it[0]);
            idg[it[0]]++;
        }

        vector<int>ans;

        queue<int>q;

        for(int i=0; i<numCourses; i++){
            if(idg[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int u = q.front();
            q.pop();
            ans.push_back(u);

            for(int v : adj[u]){
                idg[v]--;
                if(idg[v]==0){
                    q.push(v);
                }
            }
        }

        if(ans.size() != numCourses){
            ans.clear();
            return ans;
        }
        return ans;
    }
};