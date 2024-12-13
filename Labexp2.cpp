#include<iostream>
using namespace std;
struct print{
    int x= 0;
    int y= 2;
};
int main(){
    struct print p1;
    cout<<"x= "<<p1.x<<endl<<"y= "<<p1.y<<endl;
    p1.x=20;
    cout<<"x= "<<p1.x<<endl<<"y= "<<p1.y<<endl;
    return 0;
}