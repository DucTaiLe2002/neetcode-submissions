class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        if (size == 1) return nums[0];

        // prev2 đại diện cho dp[i-2], prev1 đại diện cho dp[i-1]
        int prev2 = 0;
        int prev1 = 0;

        for (int num : nums) {
            // Tính số tiền lớn nhất tại nhà hiện tại
            int current_max = max(prev1, prev2 + num);
            
            // Cập nhật lại hai biến cuốn chiếu cho bước tiếp theo
            prev2 = prev1;
            prev1 = current_max;
        }

        // Kết quả cuối cùng nằm ở nhà cuối cùng xét qua (prev1)
        return prev1;
    }
};