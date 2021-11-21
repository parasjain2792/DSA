//link:https://leetcode.com/problems/word-break/submissions/
class Solution {
public:
   static bool cmp(string s1,string s2){
        if(s1.size()>s2.size()){
            return true;
        }
       return false;
    }
     bool helper(string s,vector<string> &dict,unordered_map<string,bool> &umap){
          if(s.size()==0){
            return true;
            
        }
         else if(umap.count(s)){
             return umap[s];
         }
        
        for(int i=0;i<dict.size();i++){
            string s1=s.substr(0,dict[i].size());
            if(s1==dict[i] and helper(s.substr(dict[i].size()),dict,umap)){
                umap[s]=true;
                return true;
            }
        }
         umap[s]=false;
         return false;   
     }
    bool wordBreak(string s, vector<string>& dict) {
        bool val[s.size()];
        for(int i=0;i<s.size();i++){
            val[i]=false;
        }
        unordered_map<string,bool> umap;
        
        return helper(s,dict,umap);
        
    }
};
