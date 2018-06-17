#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class S {
public:
	int a,f,p;
	S(int _a, int _f, int _p) : a(_a), f(_f), p(_p) {}
};

bool sort1(S& l, S& r)
{
	return l.a < r.a;
}

bool sort2(S& l, S& r)
{
	return l.f - l.p < r.f - r.p;
}

int N,K;
vector<pair<int,int> > M;
vector<S> B;

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		B.clear();
		M.clear();
		scanf("%d %d", &N, &K);
		for(int i=0; i<N; i++) {
			int a,f,p;
			scanf("%d %d %d", &a, &f, &p);
			B.push_back(S(a,f,p));
		}
		sort(B.begin(), B.end(), sort1);
		int startTime = 101;
		int endTime = 0;
		for(int i=0; i<K; i++) {
			int s,e;
			scanf("%d %d", &s, &e);
			startTime = min(startTime, s);
			endTime = max(endTime, e);
			M.push_back(make_pair(s,e));
		}
		int count = 0;
		for(int time=startTime; time<endTime; time++) {
			int avail = 0;
			for(int i=0; i<K; i++) {
				if( M[i].first <= time && time < M[i].second )
					avail++;
			}

			sort(B.begin(), B.end(), sort2);
			for(int i=0; i<N && avail; i++) {
				if( B[i].a <= time && time < B[i].f && B[i].p ) {
					avail--;
					B[i].p--;
					if( B[i].p == 0 )
						count++;
				}
			}
		}
		printf("Case #%d\n", test+1);
		if( count == B.size() )
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}