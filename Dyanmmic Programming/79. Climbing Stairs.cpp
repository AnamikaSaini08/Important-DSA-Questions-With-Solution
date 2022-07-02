class Solution {
    int dp[46];
public:
    int solve(int i , int n)
    {
        if(i==n)
            return 1;
        if(i>n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        return dp[i] = (solve(i+1,n) + solve(i+2 , n));
    }
    int climbStairs(int n) {
        memset(dp,-1, sizeof(dp));
        return solve(0,n);
    }
};