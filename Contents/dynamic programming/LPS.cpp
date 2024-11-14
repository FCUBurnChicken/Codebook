int LPS(vector<vector<int>>& dp, string& s, int l, int r){
    if(~dp[l][r]) return dp[l][r];
    if(l == r) return dp[l][r] = 1;
    if(l > r) return dp[l][r] = 0;
    if(s[l] == s[r]) return dp[l][r] = LPS(dp, s, l+1, r-1) + 2;
    return dp[l][r] = max(LPS(dp, s, l + 1, r), LPS(dp, s, l, r - 1));
}