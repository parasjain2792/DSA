//link https://www.codingninjas.com/codestudio/problems/good-arrays_1404723


int goodArrays(vector<int> &a, int n) {
	// Write your code here.
    int leftOsum=0;
    int leftEsum=0;
    int rightOsum=0;
    int rightEsum=0;
    int count=0;
    for(int i=0;i<n;i++){
        if(i%2==0)
            rightEsum+=a[i];
        else
            rightOsum+=a[i];
    }
    for(int i=0;i<n;i++){
        if(i%2==0)
        {
            rightEsum-=a[i];
            if(leftOsum+rightEsum==rightOsum+leftEsum)
                count++;
            leftEsum+=a[i];
        }
        else{
            rightOsum-=a[i];
            if(leftOsum+rightEsum==rightOsum+leftEsum)
                count++;
            leftOsum+=a[i];
        }
    }
    return count;
}
