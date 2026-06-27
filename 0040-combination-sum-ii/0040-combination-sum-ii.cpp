class Solution {
public:
    vector<vector<int>> ans;  

    void getallcombination(vector<int>& arr, int idx, int tar, vector<int>& combination) {
        if (tar == 0) {
            ans.push_back(combination);
            return;
        }

        for (int i = idx; i < arr.size(); i++) {
            // skip duplicates
            if (i > idx && arr[i] == arr[i-1]) continue;

            if (arr[i] > tar) break; 

            combination.push_back(arr[i]);
            getallcombination(arr, i+1, tar - arr[i], combination);
            combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());   
        vector<int> combination;
        getallcombination(arr, 0, target, combination);
        return ans;
    }
};
