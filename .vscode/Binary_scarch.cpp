#include<iostream>
using namespace std;
int binaryscarch(int arr[],int n,int s){
 int low=0;
 int high=n-1;
 int mid;
 while (low<=high)
 {
    mid=(high+low)/2;
    if(arr[mid]==s){
        return 1;
    }else if(arr[mid]>s){
       high=mid-1;
    }else{
      low=mid+1;
    }
 }
   return -1;
}
int main(){
    int arr[5]={10,20,30,40,50};
    int s=binaryscarch(arr,5,2);
    if(s==1){
        cout<<"found";
    }else
    {
      cout<<"not found";
    }
}

