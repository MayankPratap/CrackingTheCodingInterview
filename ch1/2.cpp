#include<bits/stdc++.h>
using namespace std;

#define ff first
#define ss second


bool checkPermutation(string str1,string str2){

	map<char,int>freq1;
	map<char,int>freq2;

	if(str1.size()!=str2.size()){

		return false;

	}

	for(int i=0;i<(int)str1.size();++i){

		freq1[str1[i]]+=1;
		freq2[str2[i]]+=1;

	}

	map<char,int>::iterator it;

	bool check=true;

	for(it=freq1.begin();it!=freq1.end();++it){

		if(freq1[it->ff]!=freq2[it->ff]){

			check=false;
			break;
		}
	}

	return check;

}

int main(){

	string str1,str2;
	cin>>str1>>str2;

	cout<<checkPermutation(str1,str2)<<"\n";

	return 0;
}