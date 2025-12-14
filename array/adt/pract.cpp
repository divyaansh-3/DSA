#include<iostream>
using namespace std;
class array{
    private:
    int *a;
    int size;
    int length;
    public:
    array(){
        size=10;
        a=new int [10];
        length=0;
    }
    array(int sz){
        size=sz;
        length=0;
        a=new int[size];
    }
    ~array(){
        delete []a;
    }
    void display();
    void insert(int index,int x);
    int Delete(int index);

};
void array::display(){
    for(int i=0;i<length;i++){
        cout<<a[i]<<" ";
        
    }
    cout<<endl;
}
void array::insert(int index,int x){
    if(index>=0 && index<=length){
        for(int i=length-1;i>=index;i--){
            a[i+1]=a[i];

        }
        a[index]=x;
        length++;
    }

}
int array::Delete(int index){
    int x=0;
    if(index>=0 && index<length){
        x=a[index];
        for(int i=index;i<length-1;i++){
            a[i]=a[i+1];
        }
        length--;
    }
    return x;
}
int main(){
    array arr(10);
    arr.insert(0,5);
    arr.insert(1,6);
    arr.insert(2,9);
    arr.display();
    cout<<arr.Delete(0)<<endl;
    arr.display();
}