#include<bits/stdc++.h>
using namespace std;

void urlify(char str[],int len){

	len+=1;  // To include null character in our algo

	int cnt=0;  // No of spaces  

	for(int i=len-1;i>=0;--i){

		if(str[i]==' ')
			cnt+=1;
	}

	for(int i=len-1;i>=0;--i){

		if(str[i]==' '){

			cnt-=1;
			str[i+2*cnt]=str[i];

		}
		else{

			str[i+2*cnt]=str[i];

		}

	}

	len+=2*cnt;

	for(int i=0;i<len-1;++i){

		if(str[i]==' '){
			str[i]='%';
			str[i+1]='2';
			str[i+2]='0';

		}

	}

	printf("%s",str);

}

int main(){

	char str[100000];  // Character array to store characters of string.
	int len;      // True length of string.
	fgets(str,100000,stdin); 
 	scanf("%d",&len);

 	urlify(str,len);

	return 0;

}


