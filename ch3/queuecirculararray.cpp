#include<bits/stdc++.h>
using namespace std;

#define MAX_SIZE 101

// Creating a class named Queue

class Queue{

private:

	int A[MAX_SIZE];
	int front,rear;

public:

	// Constructor set front and rear as -1
	// For empty queue bot front and rear will be -1

	Queue(){

		front=-1;
		rear=-1;


	}

	// to check whether queue is empty

	bool IsEmpty(){

		return (front==-1 && rear==-1);

	}

	// to check whether queue is full or not

	bool IsFull(){

		return (rear+1)%MAX_SIZE==front?true:false;

	}

	// Insert an element in queue at rear end

	void Enqueue(int x){

		cout<<"Enqueuing "<<x<<"\n";

		if(IsFull()){

			cout<<"Error: Queue is Full\n";
			return;
		}

		if(IsEmpty()){

			front=rear=0;

		}
		else{

			rear=(rear+1)%MAX_SIZE;

		}

		A[rear]=x;


	}

	// Removes an element in Queue from front end

	void Dequeue(){

		cout<<"Dequeuing\n";

		if(IsEmpty()){

			cout<<"Error: Queue is empty\n";
			return;
		}

		else if(front==rear){

			// single element so after deleting it list will be empty

			rear=front=-1; 

		}

		else{

			front=(front+1)%MAX_SIZE;

		}


	}

	// Returns element at front of queue

	int Front(){

		if(front==-1){

			cout<<"Error: cannot return front from empty queue\n";
			return -1;


		}

		return A[front];

	}

	// Print the elements in queue from front to rear

	void Print(){

		int count=(rear-front+MAX_SIZE)%MAX_SIZE+1;

		cout<<"Queue        :";

		for(int i=0;i<count;++i){

			int index=(front+i)%MAX_SIZE; // Index of element when traversing circularly from front

			cout<<A[index]<<" ";

		}

		cout<<"\n\n";
	}


};

int main(){

	Queue Q; // Creating an object of class Q

	Q.Enqueue(2); Q.Print();

	Q.Enqueue(4); Q.Print();

	Q.Enqueue(6); Q.Print();

	Q.Dequeue();  Q.Print();

	Q.Enqueue(8);  Q.Print();



	return 0;
}