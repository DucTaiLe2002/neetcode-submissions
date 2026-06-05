class Solution {
public:
    
    int rob_strange(vector<int>& nums) {
        int size = nums.size();
        int dp[size] = {0};
        // if(size == 1) return nums[0];
        // if(size == 2){
        //     return nums[0]>nums[1] ? nums[0]:nums[1];
        // }
        dp[0] = nums[0];
        dp[1] = nums[0]>nums[1] ? nums[0]:nums[1];
        int i =2;
        int total_max = dp[0] > dp[1] ? dp[0]:dp[1];
        while(i<size){
            int max = 0;
            for(int j =0;j < i-1;j++){
                if(dp[j] + nums[i] > max){
                    max = dp[j] + nums[i];
                }
            }
            dp[i] = max;
            if(dp[i] > total_max){
                total_max = dp[i];
            }
            i++;
        }

        return total_max;
    }
    int rob(vector<int>& nums){
        int size = nums.size();
        int dp[size] = {0};
        if(size == 1) return nums[0];
        if(size == 2){
            return nums[0]>nums[1] ? nums[0]:nums[1];
        }
        if(size == 3){
            if(nums[0] > nums[1] && nums[0] > nums[2]){
                return nums[0];
            } else if(nums[1] > nums[0] && nums[1] > nums[2]){
                return nums[1];
            } else return nums[2];
        }
        vector<int> sub_vector_1(nums.begin(), nums.end() - 1);
        vector<int> sub_vector_2(nums.begin()+1, nums.end());
        return max(rob_strange(sub_vector_1),rob_strange(sub_vector_2));

    }
   
};