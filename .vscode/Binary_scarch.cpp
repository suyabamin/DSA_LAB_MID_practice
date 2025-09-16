#include<iostream>
using namespace std;
int binaryscarch(int arr[],int n,int s){
int scarched=s;
  int high=n-1;
  int low=0;
  int mid;
  while (low<=high)
  {
    mid=(low+high)/2;
    if(arr[mid]==scarched){
        return 1;
    }else if(arr[mid]<scarched){
       low=mid+1;
    }else{
      high=mid-1;  
    }
  }
  return -1;

}
int main(){
    int arr[5]={10,20,30,40,50};
    int s=binaryscarch(arr,5,100);
    if(s==1){
        cout<<"found";
    }else
    {
      cout<<"not found";
    }
    
  
}