
class Solution {
  public:
    string preToInfix(string pre_exp) {
        // Write your code here
        if ( pre_exp.size() == 0) return "";
        int n= pre_exp .size();
        stack <string> st ;
        for( int i= n-1 ; i>=0 ; i--){
            if ((pre_exp[i]>='a' && pre_exp[i]<='z' ) || (pre_exp[i] >= 'A' && pre_exp[i]<='Z') || ( pre_exp[i] >='0' && pre_exp[i] <='9'))
            st.push(string(1, pre_exp[i]));
        
        if (pre_exp[i] == '+' || pre_exp[i]=='-'|| pre_exp[i]=='*'|| pre_exp[i]== '/'||pre_exp[i]=='^'|| pre_exp[i]=='%'){
            string s1= st.top();  st.pop();
            string  s2 = st.top() ; st.pop();
            string s = "(" +s1 + string(1, pre_exp[i])+s2+")";
            st.push(s);
        }
        }
        return st.top();
        
    }
};