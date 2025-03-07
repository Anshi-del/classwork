#include <iostream>
using namespace std;
void insertion_sort(int arr[] ,int  n){
     for(int i=0;i<=n-2;i++){
            for(int j=i+1;j>0;j--){
                if(arr[j-1]>arr[j]){
                    int temp=arr[j-1];
                    arr[j-1]=arr[j];
                    arr[j]=temp;
                }
                else{
                    break;
                }
            }
        }
        return ;
    
}
int main (){
    
    int n;
    cout<<"enter the number of elements for array"<<endl;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++){
        cout<<"enter the element "<<i<<endl;
        cin>>arr[i];
    }
    insertion_sort(arr,n);
    for (int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
       
}