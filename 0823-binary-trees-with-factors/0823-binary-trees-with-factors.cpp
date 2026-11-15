class Solution {
public:
int mod=1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
            sort(arr.begin(),arr.end());
        unordered_map<long , long >mpp;
       mpp[arr[0]]=1;
    
        int n =arr.size();
        for(int i =1;i<n ;i++){
            int root=arr[i];
            mpp[root]=1;//wo khud ek binary tree hai 
            for(int j =0;j<i;j++){
                int LC=arr[j]; 
                if(root%LC==0&&mpp.find(arr[i]/LC)!=mpp.end()){
                    mpp[root]+=mpp[LC]*mpp[arr[i]/LC];
                }
            }
        }
        long result =0;
        for(auto &it:mpp){
        result =(result+it.second)%mod;
        }
        return result ;
    }
};