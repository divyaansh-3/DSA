#include<stdio.h>
int c(int n,int r){ //using pascal triangle
    if(r==0 || r==n){
        return 1;
    }
     else if(r>n){
        
        return -1;
    }
    else{
        return c(n-1,r-1)+c(n-1,r);
    }
}
int a[20][20];
int cmemo(int n,int r){
    if(r>n){
        return -1;
    }
    else if(r==0||r==n){
        a[n][r]=1;
        return 1;
    }
    else{
        if(a[n-1][r-1]==-1){
            a[n-1][r-1]=cmemo(n-1,r-1);
        }
        if(a[n-1][r]==-1){
            a[n-1][r]=cmemo(n-1,r);
        }
        a[n][r]=a[n-1][r-1]+a[n-1][r];
        return a[n][r];
    }
}

int main(){
    int  n,r;
    int s;
    int i;
    for(i=0;i<20;i++){
        for(int j=0;j<20;j++){
            a[i][j]=-1;
        }
    }
    printf("ENTER THE VALUES OF N AND R: ");
    scanf("%d%d",&n,&r);
    s=cmemo(n,r);
    if(s==-1){
        printf("\n R CANNOT BE GREATER THAN N");
    }
    else{
    printf("\nthe value of combination of n to r is: %d",s);
    }
    return 0;
}