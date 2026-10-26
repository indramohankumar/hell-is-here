class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int>v;
        int n=capacity.size();
        int count=0;
        for(int i =0;i<n;i++){
            v.push_back(capacity[i]-rocks[i]);
        }
        sort(v.begin(),v.end());
        for(int i =0;i<v.size();i++){
            if(additionalRocks>=v[i]){
                additionalRocks-=v[i];
                 count++;
            }
            else {
                break ;
            }
           
        }
        return count;
    }
};