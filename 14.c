#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        unsigned long long a,b,r,x,min=0,f1,f2,f3,tem;
        scanf("%llu %llu %llu",&a,&b,&r);
        if(a<b){
            tem=a;
            a=b;
            b=tem;
        }
        f1=a;
        f2=b;
        f3=r;
        int aa[100],bb[100],rr[100],aaa=0,bbb=0,rrr=0,anon[100],anon2=0;
        while(a>0){
            aa[aaa++]=a%2;
            a/=2;
        }
        while(b>0){
            bb[bbb++]=b%2;
            b/=2;
        }
        while(r>0){
            rr[rrr++]=r%2;
            r/=2;
        }
        for(int i=0;i<aaa;i++) printf("%d ",aa[i]);
        printf("\n");
        for(int i=0;i<bbb;i++) printf("%d ",bb[i]);
        printf("\n");
        for(int i=0;i<rrr;i++) printf("%d ",rr[i]);
        printf("\n");
        int i=0;
        while(i<rrr && i<aaa && i<bbb){
            //printf("a %d b %d r %d\n",aaa,bbb,rrr);
            if(i>=aaa && i>=bbb && rr[i]==1) anon[anon2++]=0;
            else if(i>=bbb && rr[i]==1 && aa[i]==1) anon[anon2++]=1;
            else if(i>=aaa && rr[i]==1 && bb[i]==1) anon[anon2++]=1;
            else if((aa[i]==1 && bb[i]==1 && rr[i]==1)) anon[anon2++]=1;
            else anon[anon2++]=0;
            i++;
        }
        for(int i=0;i<anon2;i++){
            if(anon[i]==1) min+=pow(2,i);
        }
        for(int i=0;i<anon2;i++) printf("%d ",anon[i]);
        printf("%llu\n",anon2);
        printf("%llu %llu %llu\n",min,f1^min,f2^min);
        printf("%llu\n",llabs((f1^min)-(f2^min)));
    }
}