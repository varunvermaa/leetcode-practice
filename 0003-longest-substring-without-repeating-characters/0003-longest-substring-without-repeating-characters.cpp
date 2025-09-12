class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n == 0) {
            return 0;
        }
        int l=0, r;
        set<char> charset;
        int maxlength = INT_MIN;
        
        for(r=0; r<n; r++){
          while(charset.count(s[r])){
            charset.erase(s[l]);
            l++;
          }
          charset.insert(s[r]);
          maxlength = max(maxlength, r-l+1);

        }
        return maxlength;
    }
};