class Solution {
public:
    int addDigits(int num) {
        if(num==0) return 0;
        int sum=0;
        string s=to_string(num);
        for(int i =0;i<s.length();i++){
             sum+=s[i]-'0';
        }
        if(sum >=10){
            return addDigits(sum);
        }
        return sum;
    }
};