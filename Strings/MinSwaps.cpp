//link:https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/submissions/
class Solution {
public:
    int minSwaps(string s) {
        int open=0;
        int close=0;
        int idx=0;
        int ans=0;
        vector<int> arr;
        int n=s.size();
        for(int i=n-1;i>=0;i--){
            if(s[i]=='[')
                arr.push_back(i);
        }
        for(int i=0;i<n;i++){
          if(s[i]=='['){
              open++;
          }
            else{
                close++;
            }
            if(close>open){
                swap(s[i],s[arr[idx]]);
                ans++;
                close--;
                open++;
                idx++;
            }
        }
        return ans;
    }
};
