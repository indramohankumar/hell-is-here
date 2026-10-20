class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
       int  n =plantTime.size();
       vector<pair<int,int>>vec(n);//this is for sorting of {plant time and grow time }
       for(int i =0;i<n ;i++){
        vec[i]={plantTime[i],growTime[i]};
       }
       //sort grow time in decending order 
       auto lambda=[](pair<int,int>&p1 ,pair<int,int>&p2){
        return p1.second>p2.second;
       };
       sort(vec.begin(),vec.end(),lambda);
int maxbloomdays=0;
int prevplant=0;
for(int i =0;i<n;i++){
    int currentplanttime=vec[i].first;
    int currgrowtime=vec[i].second;
    prevplant+=currentplanttime;
    int currbloomtime=prevplant+currgrowtime;
    maxbloomdays=max(maxbloomdays,currbloomtime);
}
return maxbloomdays;

    }
};