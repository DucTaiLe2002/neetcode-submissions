#include <cstring>
class Solution {
public:

    int memo[5001][2]; // Lưu trữ kết quả: [ngày][trạng thái]
    int solve(int index,int state,vector<int>& prices){
        if (index >= prices.size()) return 0;
        if (memo[index][state] != -1) return memo[index][state];
        if(state == 0){
            return memo[index][state] = max(-prices[index]+solve(index+1,1,prices),solve(index+1,0,prices));
        }
        if(state == 1){
            return memo[index][state]= max(prices[index]+solve(index+2,0,prices),solve(index+1,1,prices));
        }
    }
    int maxProfit(vector<int>& prices) {
        memset(memo, -1, sizeof(memo));
        return solve(0,0,prices);
    }
};
