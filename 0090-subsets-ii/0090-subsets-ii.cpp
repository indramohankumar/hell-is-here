class Solution {
public:
set<vector<int>>st;
void getall(vector<int>&arr,int idx, vector<int>&combination){
   // if(idx==arr.size()) return ;
    if(idx==arr.size()){
        st.insert(combination);
        return ;
    }
    combination.push_back(arr[idx]);
    getall(arr,idx+1,combination);
    combination.pop_back();
    getall(arr,idx+1,combination);

}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> combination;
        getall(nums,0,combination);
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    

    }
};