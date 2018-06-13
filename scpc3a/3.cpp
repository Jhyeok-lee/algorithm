#include <iostream>
#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int A[100001];
int last[1000001];

vector<int> divisors(int n)
{
	vector<int> ret;
	for(int i=1; i*i<=n; i++) {
		if( n%i != 0 )
			continue;
		ret.push_back(i);
		if( i*i != n )
			ret.push_back(n/i);
	}
	return ret;
}

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		memset(A, 0, sizeof(A));
		memset(last, 0, sizeof(last));
		scanf("%d %d", &N, &M);
		for(int i=1; i<=N; i++)
			scanf("%d", &A[i]);
		vector<pair<int,pair<int,int> > > query;
		for(int i=0; i<M; i++) {
			int b,l,r;
			scanf("%d %d %d", &b, &l, &r);
			query.push_back(make_pair(r, make_pair(l,b)));
		}
		sort(query.begin(), query.end());
		int ret = 0;
		int prev = -1;
		for(int i=0; i<M; i++) {
			int b = query[i].second.second;
			int l = query[i].second.first;
			int r = query[i].first;
			for(int j=prev+1; j<=r; j++) {
				int n = A[j];
				vector<int> div = divisors(n);
				for(int k=0; k<div.size(); k++)
					last[div[k]] = j;
			}
			vector<int> divB = divisors(b);
			for(int j=0; j<divB.size(); j++) {
				if( last[divB[j]] < l )
					ret++;
			}
			prev = r;
		}
		printf("Case #%d\n%d\n", test+1, ret);
	}
	return 0;
}