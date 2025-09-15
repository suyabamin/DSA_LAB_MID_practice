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
            int temp=arr[j+1];
            arr[j+1]=arr[j];
            arr[j]=temp;
        }
    }
  }
   print(arr,n);

}
void insersionsort(int arr[],int n){
    for(int i=1;i<n;i++){
         int temp= arr[i];
        int j=i-1;

        while (j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
        
    }
    print(arr,n);
}
void selectionsort(int arr[],int n){
  for(int i=0;i<n-1;i++){
    int mindex=i;
    for(int j=i+1;j<n;j++){
        if(arr[j]<arr[mindex]){
            mindex=j;
        }
    }
    int temp=arr[i];
    arr[i]=arr[mindex];
    arr[mindex]=temp;
  }
  print(arr,n);
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
  //  bubbolsort(arr,n);
   // cout<<endl<<"insersion sort-";
   // insersionsort(arr,n);
    cout<<endl<<"selection sort---";
     selectionsort(arr,n);
    
}
