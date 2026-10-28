class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalgas=0;
int totalcost=0;
        for(int i =0;i<gas.size();i++){
             totalgas+=gas[i];
        }
        for(int i=0;i<cost.size();i++){
             totalcost+=cost[i];
        }
        if(totalgas<totalcost) return -1;
        int currindex=0;
        int total=0;
        for(int i =0;i<gas.size();i++){
            total+=gas[i]-cost[i];
             if(total<0){
            currindex=i+1;
            total=0;
        }
        }
       return currindex;

    }
};