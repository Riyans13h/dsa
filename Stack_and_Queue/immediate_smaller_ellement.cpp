// User function template for C++
class Solution {
  public:
    void immediateSmaller(vector<int>& arr) {
        //  code here
        int n =  arr.size(); stack<int>st;
        vector <int>ans ( n, -1);
         for ( int i = n-1 ; i>=0 ; i--){
             int val =  arr[i];
             if (!st.empty() && st.top()<arr[i]){
                 arr[i] = st.top();
                 st.push(val);
                 continue;
             }
            
            arr[i] =-1;
             st.push ( val);
         } 
         
    }
};