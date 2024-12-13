#include<iostream>
using namespace std;
class A{
    int a;
    public:
    void getdata(){
        cout<<"enter a number:"<<endl;
        cin>>a;
        display();
    }
    private:
    void display(){
        cout<<"values of a is: "<<a<<endl;
    }
};
int main(){
    A b;
    b.getdata();
    return 0;
}