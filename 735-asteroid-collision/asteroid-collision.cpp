class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        int n = a.size();
        stack<int>s;
        
        for(int i=0; i<n; i++){
            bool des = false;
            while(!s.empty() && (a[i]<0 && s.top()>0)){
                if(abs(s.top())>abs(a[i])){
                    des = true;
                    break;
                }else if(abs(s.top())<abs(a[i])){
                    s.pop();
                    
                }else{
                    s.pop();
                    des = true;
                    break;
                }
                
            }
            if(!des)
            s.push(a[i]);
            
        }

        vector<int>ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};