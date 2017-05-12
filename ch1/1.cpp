#include<bits/stdc++.h>
using namespace std;

bool checkUnique(string str){

	//map<char,bool> mapa;

	int i=0;

	sort(str.begin(),str.end());

	for(i=1;i<(int)str.size();++i){

		if(str[i]==str[i-1])
			break;

	}

	if(i==(int)str.length())
		return true;
	else
		return false;


}

int main(){

   string str;
   cout<<"Enter a string: ";
   cin>>str;

   if(checkUnique(str)){
 
       printf("Unique");

   }

   else{

   	 printf("Not unique");

   }


}