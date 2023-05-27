#include <stdio.h>

int main() {
    int number,capacity;
    printf("\nEnter item number: ");
    scanf("%d",&number);
    int profit[number],weight[number];
    printf("\nEnter profit and weight of items:\n");
    for(int i=0;i<number;i++){
        scanf("%d %d",&profit[i],&weight[i]);
    }
    printf("\nEnter Knapsack Capacity: ");
    scanf("%d",&capacity);

    int dp[number+1][capacity+1];
    for (int i = 0; i <= number; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            }
            else if (weight[i - 1] <= w) {
                if(profit[i - 1] + dp[i - 1][w - weight[i - 1]]>dp[i - 1][w]){
                    dp[i][w]=profit[i - 1] + dp[i - 1][w - weight[i - 1]];
                }
                else{
                    dp[i][w]=dp[i - 1][w];
                }
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    int max_profit = dp[number][capacity];

    printf("\nMaximum profit that can be obtained: %d\n\n", max_profit);
    return 0;
}
