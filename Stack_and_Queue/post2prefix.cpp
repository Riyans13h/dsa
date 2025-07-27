// User function Template for C++

class Solution {
  public:
    string postToPre(string pre_exp) {
        string  s =  pre_exp;
        int n = s.size();
        if (n==0 ) return "";
        stack<string> st ;
        for(int i=0 ; i <n ; i++){
            char ch = pre_exp[i];

            if ((ch >= 'a' && ch <= 'z') || 
                (ch >= 'A' && ch <= 'Z') || 
                (ch >= '0' && ch <= '9')) 
            {
                st.push(string(1, ch));
            } 
            else if (ch == '+' || ch == '-' || ch == '*' || 
                     ch == '/' || ch == '^' || ch == '%') 
            {
                string s2 = st.top(); st.pop();
                string s1 = st.top(); st.pop();
                string s =  ch+s1+s2;
                st.push(s);
            }
        }
        return st.top();
    }
};