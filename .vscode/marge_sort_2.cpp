#include<iostream>
using namespace std;


void merge(int arr[],int l,int mid,int h){
int  i=l;
int j=mid+1;
int k=l;
int temp[100];
while (i<=mid&& j<=h)
{
    if(arr[i]<=arr[j]){
        temp[k]=arr[i];
        i++;
    }else{
        temp[k]=arr[j];
        j++;
    }
    k++;
}
   
        while (i<=mid)
        {
            temp[k]=arr[i];
            i++;
            k++;
        }
         while (j <= h) {
        temp[k] = arr[j];
        j++;
        k++;
    }

        
    for(k=l;k<=h;k++){
            arr[k]=temp[k];
        }
        
    }
    

  

int  mergeSort(int arr[],int st,int end){
    if(st<end){
        int mid=st+(end-st)/2;

        mergeSort(arr,st,mid); //left
        mergeSort(arr,mid+1,end); //right

        merge(arr,st,mid,end);
    }
}


int main(){
   int arr[5]={5,2,4,3,1};
    mergeSort(arr,0,5-1);
    for(int val:arr){
        cout<<val<<" ";
    }
    cout<<endl;
    return 0;
}