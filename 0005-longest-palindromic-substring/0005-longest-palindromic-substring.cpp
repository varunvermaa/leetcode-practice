class Solution {
public:
    string longestPalindrome(string s) {
        string lps="";
        int n = s.size();
        int low, high;
        if(n==1) return s;
        for(int i=1; i<n; i++){
            // for odd
            low=i; high=i;
            while(s[low]==s[high]){
                low--; high++;
                if(low==-1 || high==n) break;
            }
            string a = s.substr(low+1, high-low-1);
            if(lps.length() < a.length()) lps=a;

            //for even
            low=i-1;
            high = i;
            while(s[low]==s[high]){
                low--; high++;
                if(low==-1 || high==n) break;
            }
            a = s.substr(low+1, high-low-1);
            if(lps.length() < a.length()) lps=a;
        }
        if(lps.length()==1) return s.substr(0,1);
        else return lps;
    }
};