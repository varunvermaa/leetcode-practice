class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,char>> hash ('z'+1, {0,0});
        for(char a : s){
            hash[a] = {hash[a].first+1, a};
        }

        sort(hash.begin(), hash.end());
        string ans="";
        for(auto i : hash){
            ans = string(i.first, i.second) + ans;
        }
        return ans;

    }
};