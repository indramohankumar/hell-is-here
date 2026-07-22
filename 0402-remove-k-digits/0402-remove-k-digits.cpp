class Solution {
public:
    string removeKdigits(string nums, int k) {
        int n =nums.size();
        stack<char>st;
    
        for(int i =0;i< n ;i++){
            char digit =nums[i];
        while(!st.empty() &&k>0 &&st.top()>digit){
            st.pop();
            k--;
        }
        st.push(digit);
        }
        while(!st.empty()&& k>0){
            st.pop();
            k--;
        }
        string res="";
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
         while(res.size() > 0 && 
              res.back() == '0') {

            res.pop_back();
        }
        reverse(res.begin(),res.end());
        if(res.size()==0) return "0" ;
        return res ;

    }
};