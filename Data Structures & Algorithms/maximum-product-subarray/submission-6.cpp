class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;

        long long max_now = nums[0];
        long long min_now = nums[0];
        int res = nums[0];

        for(int i=1;i<nums.size();i++){
            if(nums[i]<0){
                swap(max_now,min_now);
            }
            max_now = max((long long)nums[i],max_now*nums[i]);
            min_now = min((long long)nums[i],min_now*nums[i]);

            if (max_now > INT_MAX) max_now = INT_MAX;
            if (min_now < INT_MIN) min_now = INT_MIN;

            res = max(res, (int)max_now);
        }

       
        return res;
    }
};
