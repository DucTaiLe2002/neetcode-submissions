#include <cstring>
class Solution {
public:
    // Khai báo memo làm biến thành viên
    int memo[21][2001];
    int find(vector<int>&nums,int index,int target,int total){
        if(total == target && index == nums.size()) return 1;
        if(index == nums.size()) return 0;
        if (memo[index][total + 1000] != -1) return memo[index][total + 1000];

       return memo[index][total+1000] = find(nums,index+1,target,total + nums[index]) + find(nums,index+1,target,total - nums[index]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(memo, -1, sizeof(memo));
        if (abs(target) > 1000) return 0;
        return find(nums,0,target,0);
    }
};
