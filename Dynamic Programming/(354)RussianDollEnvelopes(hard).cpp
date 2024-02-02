class Solution {
public:
    static bool comp(vector<int>&a , vector<int>&b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin() , envelopes.end() , comp);
        vector<int> ans;
        ans.push_back(envelopes[0][1]);
        for(int i= 1 ; i<envelopes.size(); i++){
            if(ans.back()<envelopes[i][1]){
                ans.push_back(envelopes[i][1]);
            }else{
                int index = lower_bound(ans.begin() ,ans.end() , envelopes[i][1]) - ans.begin();
                ans[index]=  envelopes[i][1];
            }
        }
        return ans.size();
    }
};
