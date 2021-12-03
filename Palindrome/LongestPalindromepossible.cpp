class Solution {
public:
    int longestPalindrome(string s) {
        int arr1[26]={0};
        int arr2[26]={0};
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]>='a' && s[i]<='z'){
                arr1[s[i]-'a']++;
            }
            else if(s[i]>='A' && s[i]<='Z'){
                arr2[s[i]-'A']++;
            }
        }
        int count=0;
        int flag=0;
        for(int i=0;i<26;i++){
            count+=(arr1[i]/2)*2;
            count+=(arr2[i]/2)*2;
            if(arr1[i]%2 || arr2[i]%2){
                flag=1;
            }
        }
        if(flag)
            count++;
        return count;
    }
};
