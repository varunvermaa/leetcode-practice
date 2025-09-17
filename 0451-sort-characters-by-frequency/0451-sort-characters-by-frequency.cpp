class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, char>> h('z'+1, {0,0});
        string ans;
        for(int i=0; i<s.length(); i++){
            h[s[i]]={h[s[i]].first+1, s[i]};
        }
        sort(h.begin(), h.end());// if you sorted in ascending order, you will have to prepend the string in the next for loop.
        for(auto i: h){
            ans = string(i.first, i.second) + ans; // most imp part... the string is prepended to the ans string.
        }
        return ans;
    }
};