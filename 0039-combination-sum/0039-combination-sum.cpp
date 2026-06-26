class Solution {
public:
void getallcombination(vector<int>&arr,int idx,int tar,vector<int>&combination,vector<vector<int>>&ans){
    if(idx==arr.size()||tar<0) return ;
    if(tar==0) {
        ans.push_back({combination});
        return ;
    }
    combination.push_back(arr[idx]);
getallcombination(arr,idx,tar-arr[idx],combination,ans);//single

combination.pop_back();
getallcombination(arr,idx+1,tar,combination,ans);//exclusion


}
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<int>combination;
        vector<vector<int>>ans;
        getallcombination(arr,0,target,combination,ans);
        return ans;
    }
};