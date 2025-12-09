#include<stdio.h>
double e(int x, int n){
    static double p=1,f=1;
    double r;
    if(n==0){
        return 1;
    }
    else{
        r=e(x,n-1);
        p=p*x;
        f=f*n;

        return r+ (p/f);
    }
}
double horner(int x, int n){
    static double s=1;
    if(n==0)
    return s;
    else{
        s=1+((double)x/n)*s;
        return horner(x,n-1);
    }
}
double iterative(int x, int n){
    double s=1;
    for(;n>0;n--){
        s=1+((double)x/n)*s;
    }
    return s;
}
int main (){
    printf("%lf \n",e(1,10));
    printf("%lf \n",horner(1,10));
    printf("%lf \n",iterative(1,10));
}