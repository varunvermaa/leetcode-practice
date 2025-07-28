class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // int a=0;
        // int ans=0;
        // int n=s.length();
        // set<char> b;
        // if(n==0) return 0;
        // for(int i=0; i<n; i++){
        //     if(!b.empty() && b.contains(s[i])){
        //         a=0;
        //         b={};
        //     }
        //     b.insert(s[i]);
        //     a++;
        //     ans=max(a,ans);

        // }
        // return ans;
        int n = s.length();
        if (n == 0) {
            return 0;
        }

        int maxLength = 0;
        int left = 0; 
        set<char> charSet;


        for (int right = 0; right < n; ++right) {

            while (charSet.count(s[right])) { 
                charSet.erase(s[left]);
                left++;
            }

            charSet.insert(s[right]);

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};