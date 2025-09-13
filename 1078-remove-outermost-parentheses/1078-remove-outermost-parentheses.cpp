class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        string ans;
        int a=0;
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                if(a>0) ans+=s[i];
                a++;
            }else{
                a--;
                if(a>0) ans+= s[i];
            }

            // stack <char> st;
            // string a;
            // while(!st.empty()){
            //     a.push_back(s[i]);
            //     if(st.top()=='(' && s[i]==')') st.pop();
            //     else st.push(s[i]);
            //     i++;

            // }
            // st.push(s[i]);
            // a.pop_back();
            // ans+=a;
        }
        return ans;

    }
};