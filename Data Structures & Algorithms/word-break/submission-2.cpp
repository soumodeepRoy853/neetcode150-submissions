class Solution {
private:
    bool f(int i, string& s, unordered_set<string>& st, vector<int>& dp){
        int n = s.size();
        
        if(i == n) return true;
        if(dp[i] != -1) return dp[i];

        string word = "";
        for(int j=i; j<n; j++){
      
            word += s[j];

            if(st.count(word) && f(j+1, s, st, dp)){
                return dp[i] = true;
            }
        }
        return dp[i] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());

        vector<int> dp(s.size()+1, -1);

        return f(0, s, st, dp);
    }
};
