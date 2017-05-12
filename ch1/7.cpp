// Code to rotate a matrix by 90 degree

#include<bits/stdc++.h>
using namespace std;

#define pb push_back

vector<vector<int> > rotateMatrix(vector<vector<int> >mat){

	int N=mat[0].size();

	for(int layer=0;layer<N/2;++layer){

		int firstx,firsty,secondx,secondy,thirdx,thirdy,fourthx,fourthy;

		firstx=layer;
		firsty=layer;

		secondx=N-1-layer;
		secondy=layer;

		thirdx=N-1-layer;
		thirdy=N-1-layer;

		fourthx=layer;
		fourthy=N-1-layer;

		vector<int> firstArray,secondArray,thirdArray,fourthArray,temp,temp2;

		for(int i=secondy;i<=secondx;++i){

			firstArray.pb(mat[firsty][i]);

		}

		for(int i=secondy;i<=thirdy;++i){

			secondArray.pb(mat[i][secondx]);

		}

		for(int i=thirdx;i>=fourthx;--i){

			thirdArray.pb(mat[thirdy][i]);

		}

		for(int i=fourthy;i>=firsty;--i){

			fourthArray.pb(mat[i][fourthx]);

		}

		temp=secondArray;
		secondArray=firstArray;

		temp2=thirdArray;
		thirdArray=temp;
		temp=temp2;

		temp2=fourthArray;
		fourthArray=temp;
		temp=temp2;

		firstArray=temp;

		

		int cnt=0;

		for(int i=firstx;i<=secondx;++i){

			mat[firsty][i]=firstArray[cnt];
			cnt+=1;

		}

		cnt=0;

		for(int i=secondy;i<=thirdy;++i){

			mat[i][secondx]=secondArray[cnt];
			cnt+=1;

		}

		cnt=0;

		for(int i=thirdx;i>=fourthx;--i){

			mat[thirdy][i]=thirdArray[cnt];
			cnt+=1;

		}

		cnt=0;

		for(int i=fourthy;i>=firsty;--i){

			mat[i][fourthx]=fourthArray[cnt];
			cnt+=1;

		}


	}
	
	return mat;

}

int main(){

	int N;
	cin>>N;

	// N*N matrix
	vector<vector<int> >mat(N,vector<int>(N,0));

	for(int i=0;i<N;++i){

		for(int j=0;j<N;++j)
			cin>>mat[i][j];

	}

	

	mat=rotateMatrix(mat);

	for(int i=0;i<N;++i){

		for(int j=0;j<N;++j){
			cout<<mat[i][j]<<" ";
		}	
		cout<<"\n";

	}


	return 0;
}