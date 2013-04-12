#include <stdio.h>
#include <vector>
#include <utility>
using namespace std;

typedef long long ll;
const char IN[]="carti.in",OUT[]="carti.out";

int N;ll M;int Rez;

vector<pair<int,int> > sol;
int main()
{
	int i;
	freopen(IN,"r",stdin);
	scanf("%d%lld",&N,&M);
	fclose(stdin);

	for (i=2;i<=N && i*i<=M;++i) if (M%i==0){
		int ct=1;M/=i;
		while (M%i==0) ++ct,M/=i;
		sol.push_back(make_pair(i,ct));
		Rez+=ct;
	}
	if (M!=1){
		sol.push_back(make_pair(M,1));
		++Rez;
	}

	freopen(OUT,"w",stdout);
	printf("%d\n",Rez);
	for (i=0;i<(int)sol.size();++i)
		printf("%d %d\n",sol[i].first,sol[i].second);
	fclose(stdout);


	return 0;
}
