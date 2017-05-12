#include<bits/stdc++.h>
using namespace std;

struct Node{

	int data;
	Node* link;

};


Node* Insert(int val,Node* head){   // Insert at end

	Node* temp=new Node();
	temp->data=val;
	temp->link=NULL; 

	if(head==NULL){   // Empty list

		head=temp;
		return head;

	}

	Node* temp1=head;

	while(temp1->link!=NULL){

		temp1=temp1->link;

	}

	temp1->link=temp;

	return head;

}


// Remember when skipping node or dropping them always free memory.

/*

      O(n) time , O(n) space solution


*/


Node* removeDuplicates(Node* head){   

	Node* temp=head;
	map<int,bool> mapa;   // hash map to keep track of duplicates

	while(temp!=NULL){

		mapa[temp->data]=true;

		Node* temp1=temp->link;

		while(temp1!=NULL && mapa[temp1->data]==true){

			Node* temp2;
			temp2=temp1->link;
			delete temp1;
			temp1=temp2;

		}

		temp->link=temp1;
		temp=temp->link;

	}

	return head;

}

/*

     O(n^2) time , O(1) space solution 



*/

Node* removeDuplicates2(Node* head){

	Node* slow=head;
	Node* fast;

	while(slow!=NULL){

		fast=slow;
		while(fast!=NULL && fast->link!=NULL){

			Node* temp1=fast->link;
			while(temp1!=NULL && temp1->data==slow->data){

				temp1=temp1->link;
			}

			fast->link=temp1;
			fast=fast->link;


		}

		slow=slow->link;

	}

	return head;

}

void Print(Node* head){

	Node* temp=head;

	while(temp!=NULL){

		cout<<temp->data<<" ";
		temp=temp->link;
	}


}

int main(){

	Node* head;
	head=NULL;

 	//head=Insert(4,head);
 	//head=Insert(4,head);
 	//head=Insert(1,head);
 	//head=Insert(2,head);
 	//head=Insert(1,head);
 	//head=Insert(4,head);
 	//head=Insert(5,head);
 	//head=Insert(2,head);

 	head=removeDuplicates2(head);
 	Print(head);

	return 0;
}