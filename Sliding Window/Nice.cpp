//longest substring of size 3
class Solution {
public:
   
    int count(string s) {
        if(s.size()<3) return 0;
        int count=0;
        char a=s[0],b=s[1],c=s[2];
        int n=s.size()-1;
        for(int i=3;i<=n;i++){
            if(a!=b && b!=c && c!=a) count++;
            a=b;
            b=c;
            c=s[i];
        }
       if(a!=b && b!=c && c!=a) count++;
        return count;
    }
};
int main(){
 string s;
  cin>>s;
  Solution ob;
  
  cout<<ob.count(s);
}
