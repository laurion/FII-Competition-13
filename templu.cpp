#include <stdio.h>
#include <algorithm>
#define NMax 20010
using namespace std;

typedef long long ll;
const char IN[]="templu.in",OUT[]="templu.out";
const int mod=666013;

int N,M,A,B,n,k,Rez;
int F[NMax];

int pow(int x,int p){
	int sol=1,i;
	for (i=0;(1<<i)<=p;++i){
		if ((1<<i)&p)
			sol=1LL*sol*x%mod;
		x=1LL*x*x%mod;
	}
	return sol;
}

int main()
{
	int i,c,lc;
	freopen(IN,"r",stdin);
	scanf("%d%d",&N,&M);
	fclose(stdin);

	A=N-M+1;B=M;
	N=max(A,B);

	F[1]=F[2]=1;
	for (i=3;i<=N;++i){
		F[i]=F[i-1]+F[i-2];
		if (F[i]>=mod) F[i]-=mod;
	}

	n=B-1;k=0;c=1;lc=0;
	for (i=A;i>1;--i){
		Rez=(Rez+1LL*(c-lc+mod)%mod*F[i]%mod)%mod;
		lc=c;
		c=1LL*c*(n+1)%mod;
		c=1LL*c*pow(k+1,mod-2)%mod;
		++n;++k;
	}

	n=A-1;k=0;c=1;lc=0;
	for (i=B;i>1;--i){
		Rez=(Rez+1LL*(c-lc+mod)%mod*F[i]%mod)%mod;
		lc=c;
		c=1LL*c*(n+1)%mod;
		c=1LL*c*pow(k+1,mod-2)%mod;
		++n;++k;
	}

	freopen(OUT,"w",stdout);
	printf("%d\n",Rez);
	fclose(stdout);

	return 0;
}
