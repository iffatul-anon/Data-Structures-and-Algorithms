#include<stdio.h>

int main(){
    int number,capacity;
    printf("\nEnter item number: ");
    scanf("%d",&number);
    double profit[number],weight[number],ratio[number];
    printf("\nEnter profit and weight of items:\n");
    for(int i=0;i<number;i++){
        scanf("%lf %lf",&profit[i],&weight[i]);
        ratio[i]=profit[i]/weight[i];
    }
    printf("\nEnter Knapsack Capacity: ");
    scanf("%d",&capacity);

    for(int i=0;i<number;i++){
        for(int j=i+1;j<number;j++){
            if(ratio[i]<ratio[j]){
                double tem=ratio[i];
                ratio[i]=ratio[j];
                ratio[j]=tem;

                tem=profit[i];
                profit[i]=profit[j];
                profit[j]=tem;

                tem=weight[i];
                weight[i]=weight[j];
                weight[j]=tem;
            }
        }
    }

    double max_profit=0;
    int i=0;
    while(capacity-weight[i]>=0 && i<number){
        capacity=capacity-weight[i];
        max_profit=max_profit+profit[i];
        i++;
    }
    if(i<number){
        max_profit=max_profit+(capacity*ratio[i]);
    }

    printf("\nMaximum profit that can be obtained: %0.2lf Tk\n\n", max_profit);
    return 0;
}