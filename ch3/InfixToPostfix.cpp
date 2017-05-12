// Infix to Postfix conversion using Stack.
// Assuming both operators and operands in input will be single character

#include<bits/stdc++.h>
using namespace std;

string InfixToPostfix(string expression){

	// Declaring a stack from STL

	stack<char>S;

	string postfix=""; // Initialize postfix as empty string.

	for(int i=0;i<expression.length();++i){

		// Scanning each character from left.
		// If character is a delimiter, move on.

		if(expression[i]==' ' || expression[i]==',') continue;

		
		else if(IsOperator(expression[i])){

			while(!S.empty() && S.top()!='(' && HasHigherPrecedence(S.top(),expression[i])){

				postfix+=S.top();
				S.pop();

			}

			S.push(expression[i]);


		}

		// Else if character is an operand

		else if(IsOperand(expression[i])){

			postfix+=expression[i];

		}

		else if(expression[i]=='('){

			S.push(expression[i]);

		}

		else if(expression[i]==')'){

			while(!S.empty() && S.top()!='('){

				postfix+=S.top();
				S.pop();

			}

			S.pop();

		}

	}

	while(!S.empty()){

		postfix+=S.top();
		S.pop();

	}

	return postfix;

}

bool IsOperand(char C){

	if(C>='0' && C<='9') return true;
	if(C>='a' && C<='z') return true;
	if(C>='A' && C<='Z') return true;

	return false;

}

bool IsOperator(char C){

	if(C=='+' || C=='-' || C=='*' || C=='/' || C=='^'){

		return true;

	}

	return false;
}

bool IsRightAssociative(char op){

	if(op=='^') return true;	

	return false;

}

int GetOperatorWeight(char op){

	int weight=-1;

	switch(op){

		case '+':
		case '-':
			weight=1;
		break;
		case '*':
		case '/':
			weight=2;
		break;

		case '^':
			weight=3;
		break;

	}

	return weight;

}

bool HasHigherPrecedence(char op1,char op2){

	int op1W=GetOperatorWeight(op1);
	int op2W=GetOperatorWeight(op2);

	// If operators have equal precedence, return true if they are left associative
	// return false if right associative

	if(op1W==op2W){

		if(IsRightAssociative(op1)) return false;
		else return true;

	}

	return op1W>op2W? true:false;
}



int main(){

	string expression;
	cout<<"Enter infix expression\n";

	getline(cin,expression);

	string postfix=InfixToPostfix(expression);

	cout<<"Output= "<<postfix<<"\n";

}



















	return 0;
}