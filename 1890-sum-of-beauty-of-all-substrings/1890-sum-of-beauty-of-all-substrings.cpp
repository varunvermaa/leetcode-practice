class Solution {
public:

    int beauty (string s){
        vector<int> a(26,0);
        int n=s.length()+1,m=0;
        for(int i=0; i<s.length(); i++){
            a[s[i]-'a']++;
        }
        for(int x: a){
            if(x>0){n=min(n, x);
            m=max(m,x);}
        }
        return m-n;

    }

    int beautySum(string s) {
        int total_beauty = 0;
        int n = s.length();

        for (int i = 0; i < n; ++i) {
            vector<int> freq(26, 0);
            for (int j = i; j < n; ++j) {
                freq[s[j] - 'a']++;

                int max_freq = 0;
                int min_freq = n + 1;

                for (int count : freq) {
                    if (count > 0) {
                        max_freq = max(max_freq, count);
                        min_freq = min(min_freq, count);
                    }
                }
                total_beauty += (max_freq - min_freq);
            }
        }
        return total_beauty;
    }
};