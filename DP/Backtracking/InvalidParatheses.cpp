class Solution {
public:
    void solve(string s,int mr,unordered_set<string> & st,unordered_set<string>& st2) // backtracking
    {
        // we have calculated minimun removal 
        // so start removing one by one character of s
        if (mr==0)
        {
            int nmr= getminremoval(s);   // 
            if (nmr==0  && st.find(s)==st.end())
            {
                st.insert(s);
            }
            return ;
        }
        
        for (int i=0;i<s.length();i++)
        {
            string left= s.substr(0,i);
            string right= s.substr(i+1,s.length()-i-1);
            
            if (st2.find(left+right)==st2.end())
            {
                st2.insert(left+right);
                solve(left+right,mr-1,st,st2);
                
            }
        }
        
    }
    int getminremoval(string s)
    {
        stack<char> st;
        for (int i=0;i<s.length();i++)
        {
           if (s[i]==')')
            {
                if (st.empty()) st.push(s[i]);       // if empty and '('  then push becoz this is extra
               else if (st.top()=='(')   st.pop();    // match found so pop
               else  st.push(s[i]);                   // extra parenthesis so push
             }
            else if (s[i]=='(') st.push(s[i]);
        }
        return st.size();   // returns all extra parenthesis which makes string unbalanced
    }
    vector<string> removeInvalidParentheses(string s) {
        
        int mr= getminremoval(s);  // minimum removals allowed this is parentthesis that are extra
        unordered_set<string> st,st2;
        solve(s,mr,st,st2);
        
        vector<string> ans;
        for (auto x: st)
        {
            ans.push_back(x);
        }
        return ans;
        
    }
};
