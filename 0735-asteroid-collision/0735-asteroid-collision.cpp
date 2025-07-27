class Solution {
public:
    vector<int> asteroidCollision(vector<int>& as) {
        vector<int> a;
        for(int i=0; i<as.size(); i++){
            if(as[i]>0) a.push_back(as[i]);
            else{
                while(!a.empty() && a.back()<abs(as[i]) && a.back()>0) a.pop_back();
                if(!a.empty() && a.back()==abs(as[i])) a.pop_back();
                else if(a.empty() || a.back()<0) a.push_back(as[i]);
            }
        }
        return a;
    }
};