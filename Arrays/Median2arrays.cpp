double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()) return findMedianSortedArrays(nums2,nums1);//statement1
        int n1=nums1.size();
        int n2=nums2.size();
        int high=(n1);
        int low=0;
        
        while(low<=high){
            int cut1=(low+high)>>1;
            int cut2=(n1+n2+1)/2-cut1;
            
            int l1=(cut1==0)?INT_MIN:nums1[cut1-1];//statement 2
            int l2=(cut2==0)?INT_MIN:nums2[cut2-1];//stataement3
            
            int r1=(cut1==n1)?INT_MAX:nums1[cut1];//stataement4
            int r2=(cut2==n2)?INT_MAX:nums2[cut2];    statement5
            
            if(l1<=r2 && l2<=r1){
                if(!((n1+n2)%2))
                {
                    //cout<<max(l1,l2)<<" "<<min(r1,r2)<<endl;
                    return (max(l1,l2)+min(r1,r2))/2.0;
                    
                }
                else{
                    
                    return max(l1,l2);
                }

                
            }
            
            else if(l1>r2){
                
                high=cut1-1;
            }
            else{
                low=cut1+1;
            }
        }
        return 0.0; 
        
        
    }
/*So lets understand what the question is :
We need to get the median of the both the sorted array now the basic logic behind our intution is that we need to divide my both arrays into two parts such that sum of both the left part makes the half of the arrays and sum of right parts makes the other half of the arrays .
now my partititions are in the form of cut1 and cut 2
cut1+cut2=(n1+n2+1)/2
now whenever i wil perform cuts my array will give apex values l1 l2 r1 r2 when we divide first array it gets divided in l1 and r1 while second array turns in l2 r2 Now we know l1 will be less than r1 all we need to check is l1<=r2 same logic with the other half
So now we are clear with the partition stuff now how will i travel my partitions I will travel through the partitions of the first array and it will be low to high low being taking 0 elements from array 1 and high being take all possible elements
i will change low high on the basis of l1 and r2 values if my l1>r2 then i need to reduce l1 which will happen when i will move left means reduce the partitions of l1 so high=cut-1 I did change high so that i still have option of reducing it further
now same logic for the second condition trick being if i have to reduce cut2 here i will vary the cut1
now tricks:
statement 1 is there to always ensure that arr1 size<arr2size
statement 2,3,4,5:to see corner cases if i dont take any elements INT_MIN
i take all INT_MAX*/
