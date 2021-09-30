class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int negative=nums[0];
        int positive=nums[0];
        int product=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0){
                swap(positive,negative);
                
            }
             positive=max(nums[i],positive*nums[i]);
             negative=min(nums[i],negative*nums[i]);
            product=max(product,positive);
            
        }
        return product;
    }
};
//link:https://leetcode.com/problems/maximum-product-subarray/submissions/
