/*2.	Write a program in C++ to calculate the area of different shapes using Constructor Overloading. (e.g., circle, rectangle, triangle)*/


#include<iostream>
#include<string.h>
using namespace std;
class shapes{
    int side;
    int radius;
    int base;
    int height;
    float area;
public:
shapes(){
    cout<<"default constructor";
}
shapes(int side){
    cout<<"enter the side of square: ";
    cin>>side;
    area=side*side;
    cout<<"\nArea is : "<<area;
}
shapes(int base,int height){
    cout<<"enter the base of triangle: ";
    cin>>base;
    cout<<"enter the height of triangle: ";
    cin>>height;
    area=0.5*base*height;
}
};

int main(){
    shapes square;
    shapes(square);
}