int maxProfit(int* prices, int pricesSize) {
    int profit = 0;
    int max_profit = 0;
    int buy = 0;
    for (int i = 0; i < pricesSize; i++) {   
        if (prices[buy] < prices[i]) {
            profit = prices[i] - prices[buy];
            if (profit > max_profit) {
                max_profit = profit;
            }
        } else {
            prices[buy] = prices[i];
        }
    }
    return max_profit;
}

int main() {
    int prices[] = {7,6,4,3,1};
    int pricesSize = 5;
    int max_profit = maxProfit (prices, pricesSize);
    printf("result = %d\n", max_profit);
}
