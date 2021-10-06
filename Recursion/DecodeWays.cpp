//link:https://www.codingninjas.com/codestudio/problems/decode-ways_1092345?leftPanelTab=2
int helper(int arr[],int n,int i){
    if(i==n){
        return 1;
    }
    int a=0;
    int b=0;
    if(arr[i]>0){
        a=helper(arr,n,i+1);
        b=(i+1<n)?(arr[i]*10+arr[i+1]<=26)?helper(arr,n,i+2):0:0;
        return a+b;
    }
    else{
        return 0;
    }
    
}
int decodeWays(string strNum) {
    // Write your code here.
    int n=strNum.size();
    int arr[strNum.size()]={0};
    for(int i=0;i<n;i++){
        arr[i]=strNum[i]-'0';
    }
    return helper(arr,n,0);
}
