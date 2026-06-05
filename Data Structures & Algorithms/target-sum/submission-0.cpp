class Solution {
public:

    int find(vector<int>&nums,int index,int target,int total){
        if(total == target && (index == (nums.size()))) return 1;

        if(index >= nums.size()) return 0;

        return find(nums,index+1,target,total+nums[index]) + find(nums,index+1,target,total-nums[index]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return find(nums,0,target,0);
    }
};
