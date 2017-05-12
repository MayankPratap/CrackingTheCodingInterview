//  One Away : Given two strings find whether they are less than one edit distance away

#include<bits/stdc++.h>
using namespace std;

#define pb push_back

/* 

  Long not much beautiful code written by me 

*/

bool oneAway(string str1,string str2){

	if(str1==str2){

		return true;

	}

	else{

		if(abs((int)str1.size()-(int)str2.size())>1){
			cout<<"Farzee";
			return false;
		}

		else{

			vector<int>unmatched;

			if((int)str1.size()<(int)str2.size()){

				int i=0,j=0;

				for(;j<max((int)str1.size(),(int)str2.size());){

					if(i<min((int)str1.size(),(int)str2.size()) && str1[i]==str2[j]){


						i+=1;
						j+=1;

					}
					else{

						unmatched.pb(str2[j]);
						j+=1;

					}


				}


			}
			else if((int)str1.size()>(int)str2.size()){

				int i=0,j=0;

				for(j=0;j<max((int)str1.size(),(int)str2.size());){


					if(i<min(str1.size(),str2.size()) && str1[j]==str2[i]){

						i+=1;
						j+=1;

					}
					else{

						unmatched.pb(str1[j]);
						j+=1;

					}

				}


			}

			else{

				int i=0,j=0;

				for(j=0;j<(int)str1.size();){

					if(str1[j]==str2[j])
						j++;
					else{

						unmatched.pb(str2[j]);
						j++;

					}


				}


			}

			if(unmatched.size()>1){

				return false;


			}
			else{

				return true;

			}


		}


	}


}


/* Beautiful code */

bool oneEditAway(string first,string second){

	if(abs(first.size()-second.size())>1)
		return false;


	/* Getting shorter and longer strings */
	string s1=first.length()<second.length()?first:second;
	string s2=first.length()>second.length()?first:second;

	int index1=0;
	int index2=0;

	bool foundDifference=false;

	while(index2<s2.size() && index1<s1.size()){

		if(s1[index1]!=s2[index2]){

			// Ensure that its first difference
			if(foundDifference) return false;

			foundDifference=true;

			if(s1.length==s2.length()){  // on replace move shorter pointer

				index1++;

			}

		}

		else{

			index1++;   // If matching move shorter pointer
		}

		index2++;  // Always move longer string

	}

	return true;

}

int main(){

	string str1,str2;

	cin>>str1;
	cin>>str2;


	cout<<oneAway(str1,str2)<<"\n";



	return 0;
}