class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n =nums.size();
        int  result =0;
        int oddcount =0;
        unordered_map<int ,int> mpp;
        mpp[oddcount]=1;
        for( int  i =0;i<n ;i++){
            oddcount+=(nums[i]%2!=0);
            if(mpp.count(oddcount-k)){
                result+=mpp[oddcount-k];
            }
            mpp[oddcount]++;
        }
        return result ;
    }
};