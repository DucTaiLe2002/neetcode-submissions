class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) return 0;
        if(size == 1) return 1;

        std::vector<int> dp(size,1);
        for(int i=1;i<size;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=std::max(dp[j]+1,dp[i]);
                    // cout<<"dp tai : "<<i<<" la "<<dp[i]<<endl;
                }
            }
            
        }
        auto max_element = std::max_element(dp.begin(), dp.end());
        int max_val = *max_element;
        return max_val;
    }
};
