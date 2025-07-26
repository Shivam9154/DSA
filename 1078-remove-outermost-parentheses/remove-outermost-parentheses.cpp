class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st;
        string result="";
        char temp;
        if(s==""){
            return "";
        }
        st.push(s[0]);
        for(int i=1;i<s.size();i++){
            if(st.empty()){
                st.push(s[i]);
            }else if(s[i]=='('){
                st.push(s[i]);
                result+=s[i];
            }else if(s[i]==')'){
                st.pop();
                if(!st.empty()){
                    result+=s[i];
                }
            }
        }
        return result;
    }
};