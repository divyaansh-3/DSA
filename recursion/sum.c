#include<stdio.h>
int sum(int n){
    
    if(n<1){
        return 0;
    }
    else{
        return n+sum(n-1);
    
    }
    
}
int main(){
    int n;
    printf("ENTER THE NO OF TERMS : ");
    scanf("%d",&n);
    int s=sum(n);
    printf("\nTHE SUM OF FIRST %d NATURAL NUMEBRS IS: %d",n,s);
    return 0;
}