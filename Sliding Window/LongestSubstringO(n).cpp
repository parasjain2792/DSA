class Solution {
public:
    string findLongestSubstring(string & s, int l, int h)
    {
        // base case
        if(l>=h) return "";
        // base case : if substring length < 2 then no solution        
        if((h-l+1) < 2)return "";
        
        // keep track of upper and lower char in substring
        bitset<26>upper_track(0);
        bitset<26>lower_track(0);
        
        for(int i=l;i<=h;i++)
        {
            if(s[i]>='a' && s[i]<='z')
                lower_track[s[i]-'a']=1;
            else 
                upper_track[s[i]-'A']=1;
        }
        
        // count no of char has both upper and lower case
        int validCount = 0;
        // count no of char has only upper pr lower case
        int invalidCount = 0;        
        
        for(int i=0;i<26;i++)
        {
            if(upper_track[i]==1 && lower_track[i]==1)validCount++;
            else if(upper_track[i] != lower_track[i]) invalidCount++;
        }

        
        // no possible solution if all char has only upper or lower case
        if(validCount==0)return "";
        
        // full substring is the solution if all char has both upper and lower case
        if(invalidCount == 0)return s.substr(l,h-l+1);
        
        // max length valid substring 
        string result = "";
        int start = l;
        int curr = l;
        int index;
        // loop though current substring and call this divide conquire method for
        // substring start to current index when any char has only lower or upper case 
        // and recursively get the max valid substring length 
        while(curr <= h)
        {
            if(s[curr]>='a' && s[curr]<='z') index = s[curr]-'a';
            else index = s[curr]-'A';
            
            // invalid char found and so call recusrsion over substring start to current index
            if(upper_track[index] != lower_track[index])
            {
                string str = findLongestSubstring(s,start,curr-1);
                if(str.length() > result.length())result = str;
                start = curr + 1;
            }
            curr++;
        }
        
        if(start<h)
        {
            string str = findLongestSubstring(s,start,h);
            if(str.length() > result.length())result = str;
        }
        
        return result;
    }
    
    string longestNiceSubstring(string s) {
        
        int n = s.length();

        // no solution for string length < 2
        if(n<2) return "";
        
        // recursively find the max length valid substring
        return findLongestSubstring(s,0,n-1);
    }
};
