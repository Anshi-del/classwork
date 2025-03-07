//make a single program in which you have two clasees base and derived , base class contains some data memeners and some member function under public protected and private , you need to inherit your base class an

#include <iostream>
using namespace std;

class Base{
    public:
    int publicVar=10;
    protected:
    int protectedVar=20;
    private:
    int privateVar=30;


};

class Derived1: private Base{
    public:
    int publicVar1=100;
    protected:
    int protectedVar1=200;
    private:
    int privateVar1=300;

    public:
    void display(){
        
        cout<<"Public(now private):"<<publicVar<<endl;
        
        cout<<"Protected(now private):"<<protectedVar<<endl;
        //cout<<"Private(now Private):"<<privateVar<<endl;//inaccessible
    }
};
class Derived2: public Base{
    public:
    int publicVar2=1000;
    protected:
    int protectedVar2=2000;
    private:
    int privateVar2=3000;

    public:
    void display(){
        cout<<"Public(now public):"<<publicVar<<endl;
        
        cout<<"Protected(now protected):"<<protectedVar<<endl;
        //cout<<"Private(now Private):"<<privateVar<<endl;//inaccessible
    }
};
class Derived3: protected Base{
    public:
    int publicVar2=10000;
    protected:
    int protectedVar2=20000;
    private:
    int privateVar2=30000;

    public:
    void display(){
        cout<<"Public(now protected):"<<publicVar<<endl;
        
        cout<<"Protected(now protected):"<<protectedVar<<endl;
        //cout<<"Private(now Private):"<<privateVar<<endl;//inaccessible
    }
};
int main(){
    Derived1 d1;
    d1.display();
    // cout<<"Public from main:"<<d1.publicVar<<endl;//inaccessible
    // cout<<"Protected from main:"<<d1.protectedVar<<endl;//inaccessible
    

     Derived2 d2;
    d2.display();
    // cout<<"Public from main:"<<d2.publicVar<<endl;//inaccessible
    // cout<<"Protected from main:"<<d2.protectedVar<<endl;//inaccessible
    

     Derived3 d3;
     d3.display();
    // cout<<"Public from main:"<<d3.publicVar<<endl;//inaccessible
    // cout<<"Protected from main:"<<d3.protectedVar<<endl;//inaccessible
  
    return 0;

}