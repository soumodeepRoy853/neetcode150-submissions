class Solution {
private:
    int f(int i, string& s, vector<int>& dp){
        if(i == s.size()) return 1;
        if(s[i] == '0') return 0;

        if(dp[1] != -1) return dp[i];

        int res = f(i+1, s, dp);

        if(i+1 < s.size()){
            if(s[i] == '1' || (s[i] == '2' && s[i+1] <= '6')){
                res += f(i+2, s, dp);
            }
        }
        

        return dp[i] = res;
    }
public:
    int numDecodings(string s) {
        vector<int>dp (s.size()+1, -1);
        return f(0, s, dp);
    }
};
