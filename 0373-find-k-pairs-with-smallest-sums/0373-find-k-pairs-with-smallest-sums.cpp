class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
             priority_queue<pair<int, pair<int,int>>> pq;//max heap to store k small element 
        int  n=nums1.size();
        int m =nums2.size();
        for(int i =0;i<n ;i++){
            for(int j =0;j<m ;j++){
                int sum =nums1[i]+nums2[j];
               //add the pair if the queue size is less than k
                if(pq.size()<k){
                     pq.push({sum,{nums1[i] ,nums2[j]}});
                }
                  // If the current sum is smaller than the largest sum in the priority queue
                // remove the largest sum and add the current sum
                else if(sum<pq.top().first){
                    pq.pop();
                     pq.push({sum,{nums1[i] ,nums2[j]}});
                }
                else if(sum>=pq.top().first){
                    break ;
                }
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){

ans.push_back({   pq.top().second.first,
                pq.top().second.second});
pq.pop();
        }
           // reverse(ans.begin(), ans.end());
        return ans ;
    }
};