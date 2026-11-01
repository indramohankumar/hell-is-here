class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int n =nums.size();
        int mini =INT_MAX;
        for(int i =0;i<n-1;i+=2){
            string s1=to_string(nums[i])+to_string(nums[i+1]);
            int num=stoi(s1);
            mini=min(mini,num);
        }
        return mini;
    }
};