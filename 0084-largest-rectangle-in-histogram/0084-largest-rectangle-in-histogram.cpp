class Solution {
public:

    vector<int> nextSmaller(vector<int> a){
        stack<int> s;
        vector<int> ns;
        s.push(a.size()-1);
        ns.push_back(a.size());
        for(int i = a.size()-2; i>=0; i--){
            if(a[i]>a[s.top()]){
                ns.push_back(s.top());
            } else {
                while(!s.empty() && a[s.top()]>=a[i]){
                    s.pop();
                }
                if(s.empty()) ns.push_back(a.size());
                else ns.push_back(s.top());
            }
            s.push(i);
        }
        reverse(ns.begin(), ns.end());
        return ns;
    }

    vector<int> prevSmaller(vector<int> a){
        stack<int> s;
        vector<int> ps;
        s.push(0);
        ps.push_back(-1);
        for(int i = 1; i<a.size(); i++){
            if(a[s.top()]<a[i]) ps.push_back(s.top());
            else{
                while(!s.empty() && a[s.top()]>=a[i]){
                    s.pop();
                }
                if(s.empty()) ps.push_back(-1);
                else ps.push_back(s.top());
            }
            s.push(i);
        }
        return ps;
        
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> ns,ps;
        ns = nextSmaller(heights);
        ps = prevSmaller(heights);
        
        int ans=INT_MIN;

        for(int i = 0; i<heights.size(); i++){
            int a = heights[i]*(ns[i]-ps[i]-1);
            ans = max(ans, a);
        }
        return ans;
    }
};