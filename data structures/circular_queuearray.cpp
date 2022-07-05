#include<bits/stdc++.h>
using namespace std;

struct Queue
{
	int rear, front;
	int size;
	int *arr;
	
  Queue(int s){
    front = rear = -1;
    size = s;
    arr = new int[s];
  }
 
	void enQueue(int value);
	int deQueue();
	void print();
};

// input into circular queue
void Queue::enQueue(int value)
{
	if ((front == 0 && rear == size-1) ||(rear == (front-1)%(size-1))){
		printf("Queue Full\n");
		return;
	}
	else if (front == -1) {
		front = rear = 0;
		arr[rear] = value;
	}else if (rear == size-1 && front != 0){
		rear = 0;
		arr[rear] = value;
	}else{
		rear++;
		arr[rear] = value;
	}
}

// remove or delete from circular queue
int Queue::deQueue(){
	if (front == -1)
	{
		printf("Queue Empty\n");
		return INT_MIN;
	}

	int data = arr[front];
	arr[front] = -1;
	if (front == rear)
	{
		front = -1;
		rear = -1;
	}
	else if (front == size-1)
		front = 0;
	else
		front++;

	return data;
}

// display queue elements
void Queue::print()
{ 
	if (front == -1)
	{
		printf("Queue Empty\n");
		return;
	}
	if (rear >= front)
	{
		for (int i = front; i <= rear; i++)
			cout<<arr[i]<<" ";
	}
	else
	{
		for (int i = front; i < size; i++)
			cout<<arr[i]<<" ";

		for (int i = 0; i <= rear; i++)
			cout<<arr[i]<<" ";
	}
	cout<<"\n";
}

int main(){
    return 0;
}