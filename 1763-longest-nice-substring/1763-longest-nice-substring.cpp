class Solution {
public:
    bool isNice(string str){    
        for(char ch : str){
            char opposite;
            if(islower(ch)){
                opposite = toupper(ch);
            }
            else{
                opposite = tolower(ch);
            }
            if(str.find(opposite)==string::npos){
                return false;
            }
        }
        return true;
    }
    string longestNiceSubstring(string s) {
        string ans = "";
        for(int i=0; i<s.size(); i++){
            for(int j=i; j<s.size(); j++){
                string str = s.substr(i,j-i+1);
                if(isNice(str) && str.size()>ans.size()){
                    ans = str;
                }
            }
        }
        return ans;
    }
};