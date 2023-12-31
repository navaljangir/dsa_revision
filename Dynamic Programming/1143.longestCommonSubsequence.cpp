class Solution {
public:
    int solve(int i , int j , string&text1, string &text2 , vector<vector<int>>&dp){
        if(i>=text1.length()){
            return 0;
        }
        if(j>=text2.length()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans  =0 ;
        if(text1[i] ==text2[j]){
            ans = 1+ solve(i+1, j+1, text1, text2,dp);
        }else{
            ans = max(solve(i+1, j , text1 , text2,dp) , solve(i, j+1, text1 , text2,dp));
        }
        
        return dp[i][j] = ans;
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length() , vector<int>(text2.length() ,-1));
        return solve(0 , 0 , text1, text2 ,dp);
    }
};


// Tabulation 
class Solution {
public:
    int solveTab(string text1 , string text2){
        vector<vector<int>> dp(text1.length()+1 , vector<int>(text2.length()+1));
        for(int i = text1.length()-1; i>=0; i--){
            for(int j = text2.length()-1;j>=0;j--){
                        int ans  =0 ;
        if(text1[i] ==text2[j]){
            ans = 1+ dp[i+1][j+1];
        }else{
            ans = max(dp[i+1][j], dp[i][j+1]);
        } 
        dp[i][j] = ans;
        }
        }
        return dp[0][0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        return solveTab(text1, text2);
    }
};


//Space optimisation
class Solution {
public:
    int solveTabSO(string text1 , string text2){
        vector<int> next(text2.length()+1);
        vector<int> curr(text2.length()+1);
        for(int i = text1.length()-1; i>=0; i--){
            for(int j = text2.length()-1;j>=0;j--){
                        int ans  =0 ;
        if(text1[i] ==text2[j]){
            ans = 1+ next[j+1];
        }else{
            ans = max(next[j], curr[j+1]);
        } 
        curr[j] = ans;
        }
        next= curr;
        }
        return next[0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        return solveTabSO(text1, text2);
    }
};
