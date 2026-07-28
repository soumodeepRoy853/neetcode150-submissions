class Solution {
private:
    bool f(int i, string& s, unordered_set<string>& st){
        int n = s.size();
        
        if(i == n) return true;

        string word = "";
        for(int j=i; j<n; j++){
      
            word += s[j];

            if(st.count(word) && f(j+1, s, st)){
                return true;
            }
        }
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());

        return f(0, s, st);
    }
};
