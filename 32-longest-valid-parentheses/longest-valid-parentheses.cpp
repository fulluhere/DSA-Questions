// class Solution {
// public:
//     int longestValidParentheses(string s) {
//         int n = s.size();
//         stack<int>st;
//         int idx = 0;
//         vector<int>ans;
//         for(int i=0; i<n; i++){
//             if(s[i] == '('){
//                 st.push(i);
//             }else{
//                if(!st.empty() && s[st.top()] == '('){
//                     ans.push_back(i);
//                     ans.push_back(st.top());
//                     st.pop();
//                }
//             }


//         }
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int> st;
        st.push(-1);

        int length = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                st.push(i);
            } else {
                st.pop();

                if(st.empty()) {
                    st.push(i);
                } else {
                    length = max(length, i - st.top());
                }
            }
        }

        return length;
    }
};
//         sort(ans.begin(), ans.end());

//         int length = 0;
//         int last = -1;
//         for(int i=0; i<ans.size()-1; i++){
//             if(ans[i] + 1 == ans[i+1]){
//                 length = max(length, i-last);
//             }else{
//                 last = i;
//             }
//         }

//         return length;

//         class Solution {
// public:
//     int longestValidParentheses(string s) {
//         int n = s.size();
//         stack<int>st;
//         int idx = 0;
//         vector<int>ans;
//         for(int i=0; i<n; i++){
//             if(s[i] == '('){
//                 st.push(i);
//             }else{
//                if(!st.empty() && s[st.top()] == '('){
//                     ans.push_back(i);
//                     ans.push_back(st.top());
//                     st.pop();
//                }
//             }


//         }

//         sort(ans.begin(), ans.end());

//         int length = 0;
//         int last = -1;
//         for(int i=0; i<ans.size()-1; i++){
//             if(ans[i] + 1 == ans[i+1]){
//                 length = max(length, i-last);
//             }else{
//                 last = i;
//             }
//         }

//         return length;
//     }
// };
//     }
// };