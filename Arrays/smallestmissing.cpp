//link:https://leetcode.com/problems/first-missing-positive/submissions/
class Solution {
public:
    int segregate(vector<int> &nums){
        int index=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                swap(nums[index],nums[i]); 
                index++;
            }
           
        }
        return index;
    }
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        int shift=segregate(nums);
       // cout<<shift;
        for(int i=0;i<shift;i++){
          if(abs(nums[i])<=shift && abs(nums[i])>0 && nums[abs(nums[i])-1]>0 ){
              nums[abs(nums[i])-1]*=-1;
          }
           // cout<<nums[i]<<" ";
            
        }
     
        
        
        for(int i=0;i<shift;i++){
            if(nums[i]>0){
                return i+1;
            }
        }
        return shift+1;
    }
};
