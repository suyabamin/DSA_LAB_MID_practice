#include<iostream>
using namespace std;

struct node
{
    int value;
    node*next;
};
node*head=NULL;

void insert_begain(int n){
  node*newItem=new node();
   newItem->value=n;
   newItem->next=head;
   head=newItem;
}

void Print(){
    node*temp=head;
    while (temp!=NULL)
    {
        cout<<temp->value<<"->";
        temp=temp->next;
    }
    cout<<" "<<endl;
    

}
void insert_last(int v){
     node*newItem=new node();
     node*temp=head;
     newItem->value=v;
     while (temp->next!=NULL)
     {
        temp=temp->next;
     }
     temp->next=newItem;
     newItem->next=NULL;
     
}
void insert_after(int v,int n){
    node*newItem=new node();
    node*temp=head;
    if(head==NULL){
        insert_begain(v);
    }
    while (temp!=NULL&&temp->value!=n)
    {
        temp=temp->next;
    }
    newItem->value=v;
    newItem->next=temp->next;
    temp->next=newItem;
    
}
void deleteFirst(){
    node*temp=head;
    head=head->next;
    delete(temp);
}
void delete_after(int n){
    node*temp=head;
    while (temp!=NULL&& temp->value!=n)
    {
      temp=temp->next;
    }
    temp->next=temp->next->next;
    
}
int size(){
    node*temp=head;
    int count=0;
    while (temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    return count;
    
}
void insert_nth(int v,int n){
    node*newItem=new node();
        node*temp=head;
     for(int i=0;i<n-1;i++){
        temp=temp->next;
     }
     newItem->value=v;
     newItem->next=temp->next;
     temp->next=newItem;  
 }

 int scarch(int v){
      node*temp=head;
      int found=0;
      int count=0;
      while (temp!=NULL)
      { 
        count++;
        if(temp->value==v){
           return count;
        }
        temp=temp->next;
      }
      return 0;
 }
 void  bubbolSort(){
    int n=size();
     for(int i=0;i<n-1;i++){
         node*temp=head;
        for(int j=0;j<n-i-1;j++){
           if(temp->value>temp->next->value){
            int temp1=temp->value;
           temp->value=temp->next->value;
            temp->next->value=temp1;
           }
            temp=temp->next;
        }
    }
 }
 void insersionsort(){
    node*temp=head;
    node*i=head->next;
   while (i!=NULL)
   {
    int temp1=i->value;
      node*j=head;

      while (j!=i)
      {
       if(j->value>temp1){
         int temp2=j->value;
         j->value=i->value;
         i->value=temp2;
       }
       j=j->next;
      }
      i=i->next;
   }
   
 }
 int mid(){
    node*temp=head;
    int m=size();
    int mid=m/2;
    for(int i=0;i<mid;i++){
        temp=temp->next;
    }
   return temp->value;
 }
  node* midfor(node*slow,node*first){
   while (first!=NULL)
   {
    first=first->next->next;
    slow=slow->next;
   }
   return slow;
   
 }
 int  binaryscarch(int v){
    node*low=head;
    node*high=NULL;

    while (low!=high)
    {
        node*mid=midfor(low,high);
        if(mid->value==v){
            return 1;
        }else if(mid->value>v){
          high=mid;
        }else{
          low=mid->next;
        }
     
    }
    
  return -1;


 }
 void convertarray(){
    node*temp=head;
    int n=size();
    int arr[n];
    for(int i=0;i<n;i++){
       arr[i]= temp->value;
       temp= temp->next;
    }
    for(int i=0;i<n;i++){
      cout<<endl<<arr[i];
    }

 } node* merge(node* a, node* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    node* result;
    if (a->value <= b->value) {
        result = a;
        result->next = merge(a->next, b);
    } else {
        result = b;
        result->next = merge(a, b->next);
    }
    return result;
}

node* getMid(node* head) {
    node* slow = head;
    node* fast = head->next;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node* mergesort_helper(node* h) {
    if (h == NULL || h->next == NULL) return h;

    node* mid = getMid(h);
    node* second = mid->next;
    mid->next = NULL;

    node* left = mergesort_helper(h);
    node* right = mergesort_helper(second);

    return merge(left, right);
}

void margesort() {
    head = mergesort_helper(head);
}

void manue(){
    cout<<"------enter any choice--------"<<endl;
    cout<<"1)insert first"<<endl;
    cout<<"2)print link lest"<<endl;
    cout<<"3)insert last"<<endl;
    cout<<"4)inser after"<<endl;
     cout<<"5)delete first"<<endl;
      cout<<"6)delete after"<<endl;
      cout<<"7)size"<<endl;
      cout<<"8)insert after"<<endl;
       cout<<"9)scarch"<<endl;
          cout<<"10)Bubbol sort"<<endl;
           cout<<"11)insersion sort"<<endl;
            cout<<"12)binary scarch"<<endl;
             cout<<"13)get mid"<<endl;
             cout<<"14)convert array"<<endl;
             cout<<"15)marge sort"<<endl;
    cout<<"0)quit"<<endl;
}

int main(){
     manue();
    while (1)
    {
         cout<<"enter any choice---";
       int n;
        cin>>n;
      if(n==1){
        cout<<"enter value--";
        int v;
        cin>>v;
        insert_begain(v);
      }if(n==3){
        cout<<"enter value--";
        int v;
        cin>>v;
        insert_last(v);
      }if(n==4){
        cout<<"enter after positio-";
        int n;
        cin>>n;
        cout<<"enter value--";
        int v;
        cin>>v;
       insert_after(v,n);
      }else if(n==5){
       deleteFirst();
      }if(n==6){
        cout<<"delete after- ";
        int n;
        cin>>n;
       delete_after(n);
      }if(n==7){
      int s= size();
      cout<<endl<<"size is--"<<s<<endl;
      }if(n==8){
         cout<<"enter nth--";
       int n;
        cin>>n;
         cout<<"enter value--";
        int v;
        cin>>v;
       insert_nth(v,n); 
      }if(n==9){
         cout<<"ente numver--";
       int v;
        cin>>v;
        int s= scarch(v);
        if(s>0){
            cout<<endl<<"found in index-"<<s<<endl;
        }else{
            cout<<"not found"<<endl;
        }
 
      }if(n==10){
        bubbolSort();
      }if(n==11){
        insersionsort();
      }if(n==12){
       int v;
       cout<<"scarch any value--";
       cin>>v;
       int n= binaryscarch(v);
       if(n==1){
        cout<<endl<<"found"<<endl;
       }else{
        cout<<endl<<"not found"<<endl;
       }
      }else if(n==13){
       mid();
      
      }else if(n==14){
      convertarray();
      }else if(n==15){
     margesort();
      }
      else if(n==2){
        Print();
      }else if(n==0){
        break;
      }
    }
    
}