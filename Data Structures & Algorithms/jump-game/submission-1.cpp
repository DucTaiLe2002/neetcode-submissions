class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size,0);
        for(int i =0;i<size;i++){
            if(dp[i-1] == 0 && i  > 0) return false;
            if(i + nums[i] >= size) return true;
            for(int j = i;j<i+nums[i];j++){
                dp[j] = 1;
            }

        }
        

        return true;
    }
};
