#include <iostream>
#include <cstdio>

using namespace std;

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		int N, Q;
		long long T;
		scanf("%d %lld %d", &N, &T, &Q);
		long long people[100000];
		bool direct[100000];
		int retPeople[1000];
		for(int i=0; i<N; i++) {
			long long a,b;
			scanf("%lld %lld", &a, &b);
			if( b == 1 ) {
				people[i] = a + T;
				direct[i] = 1;
			}
			else {
				people[i] = a - T;
				direct[i] = 0;
			}
		}
		for(int i=0; i<Q; i++)
			scanf("%d", &retPeople[i]);
		
		for(int i=0; i<N-1; i++) {
			if( people[i] > people[i+1] ) {
				if( direct[i] != direct[i+1] ) {
					long long d = (people[i] + people[i+1])/2;
					people[i] = d;
					people[i+1] = d;
				}
				else {
					people[i+1] = people[i];
				}
			}
		}

		for(int i=N-1; i>0; i--) {
			if( people[i-1] > people[i] ) {
				if( direct[i-1] != direct[i] ) {
					long long d = (people[i-1] + people[i])/2;
					people[i-1] = d;
					people[i] = d;
				}
				else {
					people[i-1] = people[i];
				}
			}
		}

		printf("#%d", test+1);
		for(int i=0; i<Q; i++)
			printf(" %lld", people[retPeople[i]-1]);
		printf("\n");
	}
	return 0;
}