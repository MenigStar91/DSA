# include<bits/stdc++.h>
using namespace std;

class QUEUE{
  private:
    int front,rear;
    int arr[5];
    int size=0;
  public:
    QUEUE(){
      front=-1;
      rear=-1;
    }
    
    void insert_at_beg(int element){
      if(front==-1){
        arr[0]=element;
        front++;
        rear++;
      }else if(front==0){
        cout<<"Dequeue Full\n";
        return;
      }else{
        arr[--front]=element;
        return;
      }
    }
    
    void insert_at_end(int element){
      if(rear>=5){
        cout<<"Dequeue full\n";
        return;
      }else{
        arr[++rear]=element;
        if(front ==-1)front=0;
        size++;
      }
      return;
    }
    
    int delete_at_beg(){
      if(front==-1){
        cout<<"Dequeue Empty\n";
        return -1;
      }else if(front==rear){
        int var=arr[front];
        front=-1;
        rear=-1;
        size--;
      return var;
      }else{
        int var=arr[front];
        arr[front++]=-1;
        size--;
      return var;
      }
      
    }
    
    int delete_at_end(){
      if(rear==-1){
        cout<<"Dequeue Empty\n";
        return -1;
      }else{
        if(front ==rear)front--;
        
        int var=arr[rear];
        arr[rear--]=-1;
        size--;
        return var;
      }
    }
    
    void display(){
      for(int i=front;i<=rear;i++){
        if(arr[i]==-1)break;
        cout<<arr[i]<<' ';
      }cout<<"\n";
      return;
    }
};


int main(){
    return 0;
}