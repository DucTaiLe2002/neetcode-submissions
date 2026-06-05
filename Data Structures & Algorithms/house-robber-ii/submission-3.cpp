class Solution {
public:
    int rob_strange(vector<int>& new_list){
        int size = new_list.size();
        vector <int> dp(size,0);

        if(size == 2) return new_list[0] > new_list[1] ? new_list[0] : new_list[1];
        
        dp[0] = new_list[0];
        dp[1] = new_list[1];

        int i =2;
        while(i < size){
            int max_value_current = 0;

            for(int j =0;j<i-1;j++){
                max_value_current = dp[j]+new_list[i] > max_value_current ? 
                dp[j]+new_list[i] : max_value_current; 
            }

            dp[i] = max_value_current;
            i++;
        }

        return max(dp[size-1],dp[size-2]);
    }

    int rob(vector<int>& nums) {
        int size = nums.size();

        if(size == 1) return nums[0];
        if(size == 2) return nums[0] > nums[1] ? nums[0] : nums[1];

        vector<int> sub_vector_1(nums.begin(),nums.end()-1);
        vector<int> sub_vector_2(nums.begin()+1,nums.end());

        return max(rob_strange(sub_vector_1),rob_strange(sub_vector_2));
    }
};
