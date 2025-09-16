#include<iostream>
using namespace std;
void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
}
void bubbolsort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
           if(arr[j]>arr[j+1]){
            int temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
           }
        }
    }

}
void insersionsort(int arr[],int n){
      for(int i=1;i<n;i++){
        int temp=arr[i];
        int j=i-1;
        while (j>=0&&arr[j]>temp)
        {
           arr[j+1]=arr[j];
           j--;
        }
        arr[j+1]=temp;
      }
}
int main(){
    int n;
    cout<<"enter the array size--";
    cin>>n;
     int arr[n];
    cout<<"enter array elemenat:-";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"before sort-";
    print(arr,n);
    cout<<endl;
   // cout<<"bubbol sort--";
   // bubbolsort(arr,n);
   //print(arr,n);
   insersionsort(arr,n);
     cout<<"insersion  sort--";
    print(arr,n);
 
}