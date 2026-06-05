class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();

        vector<int>buy(size,0);
        vector<int>sell(size,0);
        if (size <= 1) return 0;
        buy[0] = -prices[0];
        sell[0] = 0;

        for(int i=1;i<size;i++){
            
            sell[i] = max(sell[i-1],buy[i-1]+ prices[i]);

            // cout<<"sell tai i = "<<i<<" : "<<sell[i]<<endl;

            if(i >=2){
                buy[i] = max(buy[i-1],sell[i-2]- prices[i]);
            }else{

                buy[i] = max(buy[i-1],0 - prices[i]);
            }

            // cout<<"buy tai i = "<<i<<" : "<<buy[i]<<endl;
        }

        return sell[size-1];
    }
};
