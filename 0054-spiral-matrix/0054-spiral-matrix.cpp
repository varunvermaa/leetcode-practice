class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        int sr = 0, sc = 0;
        int er = mat.size() - 1, ec = mat[0].size() - 1;

        while (sr <= er && sc <= ec) {
            // top row
            for (int i = sc; i <= ec; i++) 
                ans.push_back(mat[sr][i]);

            // right column
            for (int i = sr + 1; i <= er; i++) 
                ans.push_back(mat[i][ec]);

            // bottom row
            if (sr < er) {
                for (int i = ec - 1; i >= sc; i--) 
                    ans.push_back(mat[er][i]);
            }

            // left column
            if (sc < ec) {
                for (int i = er - 1; i > sr; i--) 
                    ans.push_back(mat[i][sc]);
            }

            sr++; sc++; er--; ec--;
        }
        return ans;
    }
};