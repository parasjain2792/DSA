class Solution {
public:
    bool check(string s){
        bool checkA[52]={0};
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]>='a' && s[i]<='z'){
                checkA[s[i]-'a']=1;
            }
            else{
                checkA[s[i]-'A'+26]=1;
            }
        }
        for(int j=0;j<26;j++){
            if(checkA[j] && !checkA[j+26])
            return false;
        }
        for(int j=26;j<52;j++){
            if(checkA[j] && !checkA[j-26])
                return false;
        }
        return true;
        
    }
    string longestNiceSubstring(string s) {
        int n=s.size();
        if(n<=1){
            return "";
        }
        string ans="";
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(check(s.substr(i,j-i+1)) && ans.length()<(j-i+1) )
                    ans=s.substr(i,j-i+1);
            }
        }
        
        return ans;
    }
};
