// #include <iostream>
// using namespace std;

// class A {
// public: 
//     int a;
//    // int *b;
    
//     A() {  
//         a = 10;
//        // b = &a;
//     }
// };

// void anshi(int a1,int a2) {
//     cout << &a1 << endl;
//     cout<< &a2<<endl;
//     cout<<a1<<endl;
//     cout<<a2<<endl;
// }

// int main() {
//     A a1;
//     A a2 = a1; 

//     anshi(a1.a,a2.a); 

//     return 0;
// }

// #include <iostream>
// using namespace std;
// class dc{
//     public:
//     int* data;
//      int size;
//      dc(int size) :size(size){
//         data= new int[size];
//         for(int i=0;i<size;i++){
//             data[i]=i;
//         }
//      }
//      ~dc(){
//         delete[] data;
//      }
//      dc(const dc &other,bool shallow):
//      size(other.size){
//         if(shallow){
//             data=other.data;
//         }
//         else{
//             data= new int[size];
//             for(int i=0;i<size;i++){
//                 data[i]=i;
//             }
//         }
//      }
// };
// int main(){
// dc a1(3);
// dc b1(a1,true);
// dc c1(a1,false);
// a1.data[0]=11;
// cout<<b1.data[0]<<endl;
// cout<<&b1<<endl;
// cout<<c1.data[0]<<endl;
// cout<<&c1<<endl;

// return 0;
// }


#include<bits/stdc++.h>
using namespace std;

class A{
    public:
    int num;
    int* ptr;
    A(int a1){
        this ->num = a1;
        this->ptr = &num;
    }

    void display(){
        cout<<"\nAddres:"<<&num<<endl;  
    }
};
int main(){
    A a(10);
    cout<< a.num <<" "<<a.ptr;
    a.display();
    cout<<endl;
    A b = a;
    cout<< b.num <<" "<<b.ptr;
    b.display();
    b.num=55; 
    a.num = 20;
    cout<<b.num<<" "<<a.num<<endl;
    cout<<(b.ptr)<<" "<<(a.ptr)<<endl;
 //*(b.ptr) = 20;
 //cout<<b.num<<" "<<a.num;


}