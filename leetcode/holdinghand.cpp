//link:https://leetcode.com/problems/couples-holding-hands/submissions/
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
      for(auto &i:row) i/=2;
      int cnt=0;
        int n=row.size();
        for(int i=0;i<n;i+=2){
         if(row[i]==row[i+1]){
             continue;
         }
          else{
              cnt++;
              for(int j=i+2;j<n;j++){
                  if(row[j]==row[i]){
                      swap(row[j],row[i+1]);
                      break;
                  }
              }
          }
      }
        return cnt;
    }
};
