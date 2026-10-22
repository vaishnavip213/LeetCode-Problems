class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int i = 0;
        while(i<s.size()){
            string word = "";
            while(s[i]!=' ' && i<s.size()){
                word += s[i];
                i++;
            }
            reverse(word.begin(),word.end());
            ans = ans +" "+word;
            i++;
        }
        return ans.substr(1);
    }
};