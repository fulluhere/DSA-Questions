class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if(y>=x) return y-x;

        queue<pair<int, int>>q;
        unordered_set<int>vis;
        q.push({0, x});
        vis.insert(x);
        while(!q.empty()){
            auto cur = q.front();
            q.pop();

            if(cur.second == y) return cur.first;

            if(!vis.count(cur.second+1)){
                vis.insert(cur.second+1);
                q.push({cur.first+1, cur.second+1});

            }
                

            if(cur.second>0 && !vis.count(cur.second-1)){
                vis.insert(cur.second-1);
                q.push({cur.first+1, cur.second-1});
            }
                

            if(cur.second%11 == 0 && !vis.count(cur.second/11)){
                vis.insert(cur.second/11);
                q.push({cur.first+1, cur.second/11});
            }
            if(cur.second%5 == 0 && !vis.count(cur.second/5)){
                vis.insert(cur.second/5);
                q.push({cur.first+1, cur.second/5});
            }

        }

        return -1;
    }
};