//link:https://practice.geeksforgeeks.org/problems/print-anagrams-together/1
// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  struct Trie{
    Trie* links[26];
    int leafNode=-1;
  };
  Trie* createNode(){
      Trie* root=new Trie;
      root->leafNode=-1;
      for(int i=0;i<26;i++){
          root->links[i]=NULL;
      }
      return root;
  }
  int getStringIndex(string& tag,int &anagramindex,Trie* obj){
      Trie* node=obj;
      int n=tag.size();
      for(int i=0;i<n;i++){
          if(node->links[tag[i]-'a']==NULL){
              node->links[tag[i]-'a']=createNode();
          }
          node=node->links[tag[i]-'a'];
      }
      if(node->leafNode==-1){
          node->leafNode=++anagramindex;
      }
      return node->leafNode;
  }
    vector<vector<string> > Anagrams(vector<string>& list) {
        //code here
        int n=list.size();
        int anagramindex=-1;
        vector<vector<string>> ans;
        Trie* obj=createNode();
        string tag;
        int tagindex;
        for(int i=0;i<n;i++){
            tag=list[i];
            sort(tag.begin(),tag.end());
            tagindex=getStringIndex(tag,anagramindex,obj);
            if(tagindex==ans.size()){
                ans.push_back(vector<string>(1,list[i]));
            }
            else{
                ans[tagindex].push_back(list[i]);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends
