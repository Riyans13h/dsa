// User function Template for C++

class Solution {
  public:
    string postToInfix(string exp) {
        // Write your code here
        stack<string>st;
        string s =  exp;
         int n  =  s.size();
         if (n==0) return "";
         reverse( s.begin()  , s.end());
         for( int i = n-1 ; i>=0 ; i--){
             char ch = s[i];
             if ((ch >= 'a' && ch <= 'z') || 
                (ch >= 'A' && ch <= 'Z') || 
                (ch >= '0' && ch <= '9')){
                    st.push(string(1,ch));
                }
                else if (ch == '+' || ch == '-' || ch == '*' || 
                     ch == '/' || ch == '^' || ch == '%') 
            {
                string s2 = st.top(); st.pop();
                string s1 = st.top(); st.pop();
                string s =  "("+s1 +ch+s2 +")";
                st.push(s);
            }
        }
        return st.top();
         
        
    }
};