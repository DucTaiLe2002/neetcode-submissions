class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp_sum(size,0);

        if(size == 1) return nums[0];

        dp_sum[0] = nums[0];
        dp_sum[1] = nums[1];

        if(size == 2){
            return nums[0] > nums[1] ? nums[0] : nums[1];
        }

        int i = 2;
        while(i < size){
            int max = 0;
            for(int j = 0;j<i-1;j++){
                if(dp_sum[j] + nums[i] > max){
                    max = dp_sum[j] + nums[i];
                }
            }

            dp_sum[i] = max;

            i++;
        }
        return dp_sum[size-1] > dp_sum[size-2]? dp_sum[size-1]:dp_sum[size-2];
    }
};
