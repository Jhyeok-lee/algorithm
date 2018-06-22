#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int N;
vector<int> adj[100001];
vector<int> W[100001];
vector<pair<int,pair<int,int> > > S;

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		for(int i=0; i<100001; i++) {
			adj[i].clear();
			W[i].clear();
		}
		S.clear();
		scanf("%d", &N);
		for(int i=0; i<N; i++) {
			int a,b,w;
			scanf("%d %d %d", &a, &b, &w);
			S.push_back(make_pair(a,make_pair(b,w)));
			W[w].push_back(a);
			W[w].push_back(b);
		}
		sort(S.begin(), S.end());
		for(int i=0; i<N; i++) {
			int alo = S[i].first;
			int ahi = S[i].second.first;
			for(int j=i+1; j<N; j++) {
				int blo = S[j].first;
				int bhi = S[j].second.first;
				if( blo <= ahi ) {
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
				else
					break;
			}
		}

		int lo = 0;
		int hi = maxWeight;
		while( lo < hi ) {
			int mid = (lo+hi)/2;
			if( check(mid) )
				hi = mid;
			else
				lo = mid;
		}
		printf("Case #%d\n%d\n", test+1, ret);
	}
	return 0;
}