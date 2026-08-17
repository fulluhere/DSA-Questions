

class Solution {
public:
    struct DSU{
        vector<int>parent;
        vector<int>sz;
        DSU(int n){
            parent.resize(n);
            sz.resize(n, 1);
            iota(parent.begin(), parent.end(), 0);
        }


        int find(int x, vector<int>&parent){
            if(parent[x] == x){
                return x;
            }

            return parent[x] = find(parent[x], parent);
        }

        void unite(int x, int y){
            int px = find(x, parent);
            int py = find(y, parent);

            if(px == py) return;

            if(sz[px]<sz[py]) swap(px, py);

            parent[py] = px;

            sz[px] += sz[py];
        }
    };


    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n+1);
        vector<int>ans;
        for(int i=0; i<n; i++){
            int a = edges[i][0];
            int b = edges[i][1];

            int p1 = dsu.find(a, dsu.parent);
            int p2 = dsu.find(b, dsu.parent);

            if(p1==p2){
                ans.push_back(a);
                ans.push_back(b);
            }else{
                dsu.unite(a, b);
            }
        }

        return ans;
    }
};