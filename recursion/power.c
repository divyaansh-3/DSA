#include<stdio.h>
int power(int m, int n){
    if(n==0){
        return 1;
    }
    else if(n%2==0){
        return power(m*m,n/2);
      

    }
    else{
        return m* power(m*m,(n-1)/2);
    }
}
int pow1(int m, int n){
    int s=1,i;
    for(i=0;i<n;i++){
        if(s==1){
            s=m*s;
        }
        else{
            s=s*m;
        }
        
    }
    return s;
}
int main(){
    int n;
    int m;
    printf("enter the number : ");
    scanf("%d",&m);
    printf("\nenter the power %d is to be raised: ",m);
    scanf("%d",&n);
    int s= power(m,n);
    int p=pow1(m,n);
    printf("\nthe result is: %d",s);
     printf("\nthe result is: %d",p);
    return 0;

}