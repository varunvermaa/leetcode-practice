class Solution {
public:
    vector<int> nse(vector<int> a){
        stack<int> s;
        int n=a.size();
        vector<int> b(n,n);
        for(int i=n-1; i>=0; i--){
            while(!s.empty() && a[s.top()]>=a[i]){
                s.pop();
            }
            if(s.empty()){
                b[i]=n;
            }else b[i]=s.top();
            s.push(i);
        }
        return b;
    }
    vector<int> pse(vector<int> a){
        stack<int> s;
        int n=a.size();
        vector<int> b(n,n);
        for(int i=0; i<n; i++){
            while(!s.empty() && a[s.top()]>a[i]){
                s.pop();
            }
            if(s.empty()){
                b[i]=-1;
            }else b[i]=s.top();
            s.push(i);
        }
        return b;
    }
    vector<int> nge(vector<int> a){
        stack<int> s;
        int n=a.size();
        vector<int> b(n,n);
        for(int i=n-1; i>=0; i--){
            while(!s.empty() && a[s.top()]<=a[i]){
                s.pop();
            }
            if(s.empty()){
                b[i]=n;
            }else b[i]=s.top();
            s.push(i);
        }
        return b;
    }
    vector<int> pge(vector<int> a){
        stack<int> s;
        int n=a.size();
        vector<int> b(n,n);
        for(int i=0; i<n; i++){
            while(!s.empty() && a[s.top()]<a[i]){
                s.pop();
            }
            if(s.empty()){
                b[i]=-1;
            }else b[i]=s.top();
            s.push(i);
        }
        return b;
    }
    long long subArrayRanges(vector<int>& nums) {
        long long sum=0;
        int n=nums.size();
        vector<int> nsee=nse(nums);
        vector<int> psee=pse(nums);
        vector<int> ngee=nge(nums);
        vector<int> pgee=pge(nums);
        for(int i=0; i<n; i++){
            long long a = (1ll*(ngee[i]-i)*(i-pgee[i])*nums[i])-(1ll*(nsee[i]-i)*(i-psee[i])*nums[i]);
            sum+=a;
        }
        return sum;
    }
};