#include<stdio.h>
long long GCD(long long n1, long long n2) {
    return n2==0 ? n1 : GCD(n2,n1%n2);
}
long long LCM(long long n1, long long n2){
    return (n1*n2)/GCD(n1,n2);
}
int main(){
    long long n1,n2;
    scanf("%lld %lld",&n1,&n2);
    long long gcd = GCD(n1,n2);
    long long lcm = LCM(n1,n2);
    printf("GCD - %lld\nLCM - %lld\n",gcd,lcm);    
}