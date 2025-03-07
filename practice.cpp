#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int arr[]={3,4,2,1,5};
    int n=sizeof(arr)/sizeof(arr[0]);
   // selection sort 
   int min=arr[0];
   for(int i=1;i<n;i++){
    for(int j=1;j<n;j++){
    if(arr[j]<min){
        swap(min,arr[i]);
    }
    }
   }
       // Output the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl; 
  
}