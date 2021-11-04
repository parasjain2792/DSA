class Solution {
public:
    int expand(string s,int left,int right){
        int L=left;
        int n=s.size();
        int R=right;
        while(L>=0 && R<=n-1 && s[L]==s[R]){
            L--;
            R++;
        }
        // if(left==right && right==1)
        // cout<<R<<L;
        return R-L-1;
    }
    string longestPalindrome(string s) {
        if(s.size()==1)
            return s;
        int n=s.size();
        int start=0;
        int end=0;
        for(int i=0;i<n;i++){
            int len1=expand(s,i,i);
            int len2=expand(s,i,i+1);
            int len=max(len1,len2);
            if(len>end-start+1)
            {
               // cout<<len;
                start=i-((len-1)/2);
                end=i+(len/2);
            }
        }
       // cout<<start<<" "<<end;
        return s.substr(start,end-start+1);
    }
};
