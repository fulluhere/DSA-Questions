class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans = "";
        stack<int>st;
        vector<int>remove;
        for(int i=0; i<s.size(); i++){
            bool rev = false;
            if(s[i] == '('){
                st.push(i);
            }else if(s[i] == ')'){
                if(st.empty()){
                    rev = true;
                }else{
                    st.pop();
                }
            }

            if(!rev){
                ans += s[i];
            }
        }

        while(!st.empty()){
            st.pop();
        }

        string ans2 = "";
        for(int i=ans.size()-1; i>=0; i--){
            bool rev = false;
            if(ans[i] == ')'){
                st.push(i);
            }else if(ans[i] == '('){
                if(st.empty()){
                    rev = true;
                }else{
                    st.pop();
                }
            }

            if(!rev){
                ans2 += ans[i];
            }
        }

        reverse(ans2.begin(), ans2.end());
        return ans2;
    }
};