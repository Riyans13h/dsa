// User function Template for C++

class Solution {
  public:
    string preToPost(string pre_exp) {
        string  s =  pre_exp;
        int n = s.size();
        if (n==0 ) return "";
        stack<string> st ;
        for(int i= n-1 ; i>= 0 ; i--){
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
                string s1 = st.top(); st.pop();
                string s2 = st.top(); st.pop();
                string s =  s1+s2 +ch;
                st.push(s);
            }
        }
        return st.top();
    }
};