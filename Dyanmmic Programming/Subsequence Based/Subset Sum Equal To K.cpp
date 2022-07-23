bool solve(vector<int> &arr , int i , int sum , int k , vector<vector<int>>&dp)
{
    if(sum == k)
        return true;
    if(i >= arr.size() || sum > k)
        return false;
    if(dp[i][sum] != -1)
        return dp[i][sum];
    
    return dp[i][sum] = solve(arr , i+1 , sum , k , dp) || solve(arr , i+1 , sum + arr[i] , k , dp);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>>dp(n+1 , vector<int>(k+1 , -1));
    return solve(arr , 0 , 0 , k , dp);
}


//Tabular
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<bool>>dp(n, vector<bool>(k+1 , 0));
    for(int i = 0 ; i<n ; i++)
        dp[i][0] = true;
    dp[0][arr[0]] = true;
    
    for(int i = 1 ; i<n ; i++)
    {
        for(int j = 1 ; j<=k ; j++)
        {
           bool nottake = dp[i-1][j];
           bool take = false;
           if(arr[i] <= j)
               take = dp[i-1][j-arr[i]];
           dp[i][j] = take | nottake;
        }
    }
    return dp[n-1][k];
}


//Optimized

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<bool>prev(k+1 , 0);
    vector<bool>next(k+1 , 0);
    
    for(int i = 0 ; i<n ; i++)
        prev[0] = true;
    prev[arr[0]] = true;
    next[0] = true;
    next[arr[0]] = true;
    
    for(int i = 1 ; i<n ; i++)
    {
        for(int j = 1 ; j<=k ; j++)
        {
           bool nottake = prev[j];
           bool take = false;
           if(arr[i] <= j)
               take = prev[j-arr[i]];
           next[j] = take | nottake;
        }
        prev = next;
    }
    return prev[k];
}
