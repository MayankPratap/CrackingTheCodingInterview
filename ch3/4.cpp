//  Queue via 2 Stacks

#include <bits/stdc++.h>
using namespace std;

class MyQueue{

private:

	stack<int> s1;
	stack<int> s2;

	int cnt;

public:

	MyQueue(){

		cnt=0;
	}

	void transferFromTo(int check){

		if(check==1){

			while(!s1.empty()){

				s2.push(s1.top());
				s1.pop();
			}
		}

		else{

			while(!s2.empty()){

				s1.push(s2.top());
				s2.pop();
			}


		}

	}

	void Enqueue(int x){

		transferFromTo(2);

		s1.push(x);
		cnt=0;

	}

	int Dequeue(){

		if(cnt==1){

			int x=s2.top();
			s2.pop();

			return x;

		}

		else{

			transferFromTo(1);
			int x=s2.top();
			s2.pop();
			cnt=1;
			

			return x;

		}


	}

};
int main(){

	MyQueue q;

	q.Enqueue(4);
	q.Enqueue(3);

	cout<<q.Dequeue()<<"\n";

	q.Enqueue(6);
	q.Enqueue(4);
	q.Enqueue(2);
	cout<<q.Dequeue()<<"\n";
	//q.Enqueue(1);
	cout<<q.Dequeue()<<"\n";
	cout<<q.Dequeue()<<"\n";
	cout<<q.Dequeue()<<"\n";






	return 0;
}