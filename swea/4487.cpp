#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int N;
int ret;

int main(void)
{
	setbuf(stdout, NULL);
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		scanf("%d", &N);
		priority_queue<int> pq;
		int a;
		int b;
		long long ret = 0;
		for(int i=0; i<N; i++) {
			scanf("%d", &a);
			pq.push(a);
			b = a;
			while( pq.top() > b ) {
				ret += pq.top() - b;
				int next = pq.top();
				pq.pop();
				pq.push(b);
				b = next;
			}
		}
		printf("#%d %lld\n", test+1, ret);
	}
}