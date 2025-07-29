class Solution {
public:
    vector<int> nse(vector<int> a){
        stack<int> s;
        int n=a.size();
        vector<int> b(n, 0);
        for(int i=n-1; i>=0; i--){

            while(!s.empty() && a[s.top()]>=a[i]){
                s.pop();
            }
            if(s.empty()){
               b[i]=n;
            } else b[i]=s.top();
            
            s.push(i);
        }
        
        
        return b;

    }  

    vector<int> pse(vector<int> a){
        stack<int> s;
        int n=a.size();
        vector<int> b(n, 0);
        for(int i=0; i<n; i++){

            while(!s.empty() && a[s.top()]>a[i]){
                s.pop();
            }
            if(s.empty()){
               b[i]=-1;
            } else b[i]=s.top();
            
            s.push(i);
        }
        
        
        return b;

    }  

    int sumSubarrayMins(vector<int>& arr) {
        int sum=0;
        int mod=(int)(1e9+7);
        vector<int> nsse = nse(arr);
        vector<int> psse = pse(arr); //previous smaller or equal element
        for(int i=0; i<arr.size(); i++){
            int leftEle,rightEle;
            leftEle=i-psse[i];
            rightEle=nsse[i]-i;
            sum = (sum + (1ll*leftEle*rightEle*arr[i])%mod)%mod;
        }
        return sum;
    }
};