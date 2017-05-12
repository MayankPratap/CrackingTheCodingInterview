#include<bits/stdc++.h>
using namespace std;

bool checkPalindromePermutation(string str){

	sort(str.begin(),str.end());

	if((int)str.size()==0){

		return true;

	}

	int cnt=0;    /* Keep count of same consecutive characters */
	int cntOdd=0; /* No of characters with odd frequency */

	for(int i=0;i<(int)str.size();++i){

		if(i==0)
			cnt=1;

		else
			if(str[i]==str[i-1])
				cnt+=1;
			else{

				if(cnt%2==1)
					cntOdd+=1;
				cnt=1;

			}


	}

	if(cnt%2==1)
		cntOdd+=1;

	if(cntOdd>1)
		return false;
	else
		return true;







}

int main(){

	string str;
	cin>>str;


	cout<<checkPalindromePermutation(str)<<"\n";


	return 0;
}