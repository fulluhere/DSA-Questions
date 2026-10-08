class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();

        stack<char>st;

        for(int i=0;i<n; i++){
            if(!st.empty() && s[i] == st.top()){
                st.pop();
                
            }else{
                st.push(s[i]);
            }

            
        }

        if(st.empty()){
            return "";
        }
        string x = "";

        while(!st.empty()){
            x += st.top();
            st.pop();
        }

        reverse(x.begin(), x.end());

        return x;
    }
};