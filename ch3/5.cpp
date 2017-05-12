// Sorting Stack:-  You can use one additional stack and nothing else.
#include<bits/stdc++.h>
using namespace std;

stack<int>s1;
stack<int>s2;  // A temporary stack

int main(){

	s1.push(1);
	s1.push(4);
/*	s1.push(7);
	s1.push(9);
	s1.push(3);
	s1.push(11);
	s1.push(13);
	s1.push(14);
	s1.push(10);

*/

	while(!s1.empty()){

		int cnt=0;

		int x=s1.top();
		s1.pop();

		if(s2.empty()){

			s2.push(x);
			

		}

		else{

			while(!s2.empty() && s2.top()>x){

				int y=s2.top();
				s2.pop();
				s1.push(y);
				++cnt;

			}

			s2.push(x);

			while(cnt--){

				int y=s1.top();
				s1.pop();
				s2.push(y);


			}



		}



	}


	while(!s2.empty()){

		cout<<s2.top()<<"\n";
		s2.pop();


	}


	return 0;
}