class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(),stones.end());
          int n=stones.size();
        for(int i =0;i<n-1;i++){
   if(stones.size() <= 1) break;
          
            int largest=stones.back();
             stones.pop_back();
            int second=stones.back();
           
            stones.pop_back();
            if(largest!=second){
stones.push_back(largest-second);
            }
            sort(stones.begin(),stones.end());
            
        }
        if(stones.empty()) return 0;
        return stones[0];
    
    }
};