// Zero Matrix

#include<bits/stdc++.h>
using namespace std;

#define INF (int)1e9

vector<vector<int> > zeroMatrix(vector<vector<int> >mat){

	int M=mat.size(),N=mat[0].size();

	for(int i=0;i<M;++i){

		for(int j=0;j<N;++j){

			if(mat[i][j]==0){

				mat[i][0]=INF;
				mat[0][j]=-INF;
			}

		}

	}

	

	for(int i=0;i<M;++i){

		if(mat[i][0]==INF){

			for(int j=0;j<N;++j){

				if(mat[i][j]!=-INF)
					mat[i][j]=0;

			}

		}

	}

	

	for(int j=0;j<N;++j){

		if(mat[0][j]==-INF){

			for(int i=0;i<M;++i){

				mat[i][j]=0;

			}

		}

	}

	
	return mat;
}

int main(){

	int N,M;
	cin>>M>>N;  // No of rows and then no of columns

	vector<vector<int> >mat(M,vector<int>(N,0));

	for(int i=0;i<M;++i){

		for(int j=0;j<N;++j){

			cin>>mat[i][j];

		}

	}

	
	mat=zeroMatrix(mat);

	

	for(int i=0;i<M;++i){

		for(int j=0;j<N;++j){

			cout<<mat[i][j]<<" ";

		}

		cout<<"\n";


	}



	return 0;
}