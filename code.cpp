//how can we implement a dynamic array??

#include<iostream>
using namespace std;
int heap[100];
int length=0,key=0;

void ins(int key){
int i=length;
heap[i]=key;
int parent,lc,rc;
parent=((i-1)/2);
cout<<"p="<<parent;
while(i>0){
   //condition to check root
    parent=((i-1)/2);

    if(key<=heap[parent]){
        break;
    }
    else{
        int temp=heap[parent];
        heap[parent]=heap[i];
        heap[i]=temp;
        cout<<"ok";
        }
    i=parent;       //assigning parent location to i
    }
    length++;
    cout<<"ok1\n";
}
void disp(){
for(int i=0;i<length;i++)
cout<<heap[i]<<"  ";
}

void del(){
  if(length==0)
  {
     cout<<"\nTHE HEAP IS EMPTY !!! \n \n";
  }
  else if(length==1)
  {
    length--;
  }

  //when size>1
  else
  {
    int i=0;
    heap[i]=heap[length-1];
    length--;

    //if the current node has a children
    while((2*i+1)+1<=length)
    {

      //if it has two children
      if((2*i+2)+1<=length)
      {
        int lc=heap[2*i+1];
        int rc=heap[2*i+2];
        int ind=(lc>=rc)?(2*i+1):(2*i+2);
        if(heap[i]<heap[ind])
        {
          int temp=heap[i];
          heap[i]=heap[ind];
          heap[ind]=temp;
          i=ind;
        }

      }

      //if it has only one child
      else
      {
        if(heap[i]<heap[2*i+1])
        {
          int temp=heap[i];
          heap[i]=heap[2*i+1];
          heap[2*i+1]=temp;
          i=2*i+1;
        }
        else
          break;
      }
    }
  }

};



int main(){
int key,size;
cout<<"Enter the number of elements you want to insert";
cin>>size;
cout<<"Enter the elements : \n";
for(int i=0 ; i<size ; i++){
    cout<<"Element"<<i+1<<" : ";
    cin>>key;
    ins(key);
    cout<<"inserted "<<i<<endl;;
    }
cout<<heap[length-1]<<endl;
disp();
del();
disp();
return 0;
}
