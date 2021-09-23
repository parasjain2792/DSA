   string findSubString(string str)
    {
        // Your code goes here   
        unordered_map<char,int> map;
        for(int i=0;i<str.length();i++){
            map[str[i]]++;
        }
        int n=str.length();
        unordered_map<char,int> umap;
        int release=0;
        int accquire=0;
        int start=0;
        int minimum=n;
        while(true){
            bool f1=false;
            bool f2=false;
            while(accquire<n && umap.size()<map.size()){
                umap[str[accquire]]++;
                accquire++;
                f1=true;
            }
            while(release<accquire && umap.size()==map.size()){
                if(minimum>accquire-release)
                {
                    start=release;
                    minimum=accquire-release;
                    
                }
                umap[str[release]]--;
                if(!umap[str[release]]) umap.erase(str[release]);
                
                release++;
                f2=true;
            }
            if(!f1 && !f2)
            break;
            //cout<<minimum<<endl;
        }
        
        return str.substr(start,minimum);
        
        
    }
