int minimumSum (vector<int>& arr, int n)
{
    // Write your code here.
    	int min_val[n]={0};
	min_val[0]=arr[0];
	int min_num=arr[0];
	for(int i=1;i<n;i++){
	    min_val[i]=min(min_val[i-1]+arr[i],arr[i]);
	    min_num=min(min_num,min_val[i]);
	}
// 	for(int i=0;i<n;i++){
// 	    cout<<min_val[i]<<" ";
// 	}
	
	return min_num;
}
