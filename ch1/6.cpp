// String Compression : aabcccccaaa to a2b1c5a3

#include<bits/stdc++.h>
using namespace std;

#define pb push_back

string convertToString(int num){

	string temp="";

	while(num){

		int b=num%10;
		temp.pb('0'+b);

		num=num/10;


	}

	reverse(temp.begin(),temp.end()); 

	return temp;


}

string compressString(string str){

	string newStr="";

	int cnt;

	for(int i=0;i<(int)str.size();++i){

		if(i==0){

			newStr.pb(str[i]);
			cnt=1;

		}

		else{

			if(str[i]==str[i-1]){

				cnt+=1;
			}

			else{

				string temp=convertToString(cnt);
				for(int j=0;j<(int)temp.size();++j){

					newStr.pb(temp[j]);
				}

				cnt=1;
				newStr.pb(str[i]);

			}

		}


	}

	string temp=convertToString(cnt);
	for(int j=0;j<(int)temp.size();++j){

		newStr.pb(temp[j]);

	}


	if((int)newStr.size()<(int)str.size()){

		return newStr;

	}

	else{

		return str;

	}


}

int main(){

	string str;
	cin>>str;


	cout<<compressString(str)<<"\n";


	return 0;
}