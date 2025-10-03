class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int s = n*n + 1;
        int missing, duplicate;
        vector<int> freq(s, false);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                freq[grid[i][j]]++;
            }
        }
        for(int i=0; i<s; i++){
            if(freq[i]==0) missing = i;
            if(freq[i]==2) duplicate = i;
        }
        return {duplicate, missing};
        
    }
};