class Solution {
public:
    int rev(int n) {
        int ans= 0;
        while(n > 0) {
            ans= ans * 10 + n % 10;
            n /= 10;
        }

        return ans;
    }

    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(int num : nums) {
            int key = num - rev(num);
            mpp[key]++;
        }

        long long ans= 0;
        int mod =1e9 + 7;
        for(auto it : mpp) {
            long long freq = it.second;
            ans = (ans +freq *(freq - 1) / 2) % mod;
        }

        return ans;
    }
};