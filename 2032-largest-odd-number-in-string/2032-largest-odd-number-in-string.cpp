class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size()-1;
        
        while(n>=0){
            if((num[n]-'0')%2==0) n--;
            else break;
        }
        
        return num.substr(0, n+1);
    }
};