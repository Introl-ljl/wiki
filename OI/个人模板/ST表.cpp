#include<bits/stdc++.h>
using namespace std;

struct ST{
	int LogN,N;
	vector<int>logn;
	vector<vector<int>>F1,F2;
	ST(){
		init(0);
	}
	ST(int n){
		init(n);
	}
	inline void init(int n){
		N=n;
		logn.assign(N+1,0);
		logn[1]=0;
		for(int i=2;i<=N;i++){
			logn[i]=logn[i>>1]+1;
		}
		LogN=logn[N]+1;
		F1.assign(N+1,vector<int>(LogN+1));
		F2.assign(N+1,vector<int>(LogN+1));
	}
	inline void pre(){
		for(int j=1;j<=LogN;j++){
			for(int i=1;i+(1<<(j-1))<=N;i++){
				F1[i][j]=max(F1[i][j-1],F1[i+(1<<(j-1))][j-1]);
			}
		}
		for(int j=1;j<=LogN;j++){
			for(int i=1;i+(1<<(j-1))<=N;i++){
				F2[i][j]=min(F2[i][j-1],F2[i+(1<<(j-1))][j-1]);
			}
		}
	}
	inline int querymax(int l,int r){
		int s=logn[r-l+1];
		return max(F1[l][s],F1[r-(1<<s)+1][s]);
	}
	inline int querymin(int l,int r){
		int s=logn[r-l+1];
		return min(F2[l][s],F2[r-(1<<s)+1][s]);
	}
};
