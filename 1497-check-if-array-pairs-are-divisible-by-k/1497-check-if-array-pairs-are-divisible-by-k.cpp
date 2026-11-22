class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int>mpp(k,0);
        for(int num:arr){
            int rem=(num%k+k)%k;
            mpp[rem]++;
        }
        if(mpp[0]%2!=0){
            return false ;
        }
        for(int rem=1;rem<=k/2;rem++){
            int counter=k-rem;
            if(mpp[counter]!=mpp[rem]){
                return false ;
            }
        }
        return true ;
    }
};