class Solution {
private:
    int f(int i, string& s){
        if(i == s.size()) return 1;
        if(s[i] == '0') return 0;

        int res = f(i+1, s);

        if(i+1 < s.size()){
            if(s[i] == '1' || (s[i] == '2' && s[i+1] <= '6')){
                res += f(i+2, s);
            }
        }
        

        return res;
    }
public:
    int numDecodings(string s) {
        return f(0, s);
    }
};
