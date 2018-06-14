#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

class S {
public:
	int a,f,p;
	S(int _a, int _f, int _p) : a(_a), f(_f), p(_p) {}

	bool operator < (const& S rhs)
	{
		return a>rhs.a?a>rhs.a:(f>rhs.f?f>rhs.f:p<rhs.p);
	}
}

int N,K;

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		scanf("%d %d", &N, &K);
		priority_queue<S> pq;
		for(int i=0; i<N; i++) {
			int a,f,p;
			scanf("%d %d %d", &a, &f, &p);
			pq.push()
		}
	}
	return 0;
}