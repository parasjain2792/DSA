//Given two strings s and t of lengths m and n respectively, return the minimum window substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>map(128,0);
        for(auto ch:t) map[ch]++;
        int begin=0;
        int end=0;
        int head=0;
        int counter=t.size();
        string ans="";
        while(end<s.size()){
          if(map[s[end++]]-->0) counter--;  
          while(counter==0){
              if(ans.length()==0 ||ans.length()>(end-begin))
                  ans=s.substr(begin,end-begin);
              if(map[s[begin++]]++==0) counter++;
          }  
            
            
        }
        
        return ans;
        
    }
};

int main(){
  
  
  
}
//Link:https://leetcode.com/problems/minimum-window-substring/
