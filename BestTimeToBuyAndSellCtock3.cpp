class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if (prices.size() < 2)
            return 0;
        
        int maxOneBuy = max(-prices[0], -prices[1]);
        int maxOneSell = prices[1] - prices[0];
        int maxTwoBuy = numeric_limits<int>::lowest();
        int maxTwoSell = numeric_limits<int>::lowest();
        
        for (int i = 2; i < prices.size(); ++i)
        {
            int prevOneBuy =  maxOneBuy;
            int prevOneSell = maxOneSell;
            int prevTwoBuy = maxTwoBuy;
            int prevTwoSell = maxTwoSell;
            
            maxOneBuy = max(prevOneBuy, -prices[i]);
            maxOneSell = max(prevOneSell, prevOneBuy + prices[i]);
            maxTwoBuy = max (prevTwoBuy, prevOneSell - prices[i]);
            if (i > 2)
                maxTwoSell = max(prevTwoSell, prevTwoBuy + prices[i]);
                
        }
        
        auto ans = max(max(maxOneBuy, maxOneSell), max(maxTwoBuy, maxTwoSell));
        return max(ans, 0);
        
        
    }
};