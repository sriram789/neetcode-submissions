class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int lowPrice = prices[0];

        for (int index = 0 ; index < prices.size(); index++) {
            maxProfit = max(maxProfit, prices[index] - lowPrice);
            lowPrice = min(lowPrice, prices[index]);
        }

        return maxProfit;
    }
};
