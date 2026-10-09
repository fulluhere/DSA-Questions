class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        string ans = "";
        vector<int>freq(26, 0);
        vector<bool>vis(26, false);
        stack<int>st;
        for(int i=0; i<n; i++){
            freq[s[i]-'a']++;
        }

        for(char c: s){
            freq[c - 'a']--;

            if(vis[c-'a']){
                continue;
            }

            while(!st.empty() && st.top()>c && freq[st.top()-'a']>0 ){
                vis[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(c);
            vis[c-'a'] = true;
        }
        

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};