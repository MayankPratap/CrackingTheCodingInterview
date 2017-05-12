//  SetOfStacks Implementation

#include<bits/stdc++.h>
using namespace std;

class SetOfStacks{

private:

	int capacity,index;
	stack<int> arr[10]; // Array to keep stack objects

public:

	SetOfStacks(){
		capacity=2;
		index=-1;
		stack<int> S;
		arr[++index]=S;
	}

	void push(int x){

		if(arr[index].size()>=capacity){

			
			stack<int> S;
			arr[++index]=S;

		}

		arr[index].push(x);

	}

	int pop(){

		int x=arr[index].top();
		arr[index].pop();

		if(arr[index].size()==0){

			index-=1;

		}

		return x;

	}

	int popAt(int index){

		int x=arr[index].top();
		arr[index].pop();

		return x;

	}



};


int main(){

	SetOfStacks a;

	//printf("Hello\n");

	a.push(4);
	a.push(2);

	a.push(3);
	a.push(5);
	cout<<a.pop()<<"\n";
	cout<<a.popAt(0)<<"\n";

	cout<<a.pop()<<"\n";

	a.push(7);

	cout<<a.pop()<<"\n";









	return 0;
}