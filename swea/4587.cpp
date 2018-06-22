#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class Node {
public:
	int prev;
	int next;
	Node()
	{
		prev = 0;
		next = 0;
	}
};

int N, M;
vector<Node> n;

void A(int x, int y)
{
	n[n[x].prev].next = n[x].next;
	n[n[x].next].prev = n[x].prev;
	n[n[y].prev].next = x;
	n[x].prev = n[y].prev;
	n[x].next = y;
	n[y].prev = x;
}

void B(int x, int y)
{
	n[n[x].prev].next = n[x].next;
	n[n[x].next].prev = n[x].prev;
	n[n[y].next].prev = x;
	n[x].prev = y;
	n[x].next = n[y].next;
	n[y].next = x;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	int Case;
	//scanf("%d", &Case);
	cin >> Case;
	for(int test=0; test<Case; test++) {
		//scanf("%d %d", &N, &M);
		cin >> N >> M;
		n = vector<Node>(N+2);
		for(int i=1; i<=N+1; i++) {
			n[i].prev = i-1;
			n[i].next = i+1;
		}

		for(int i=0; i<M; i++) {
			char chr;
			int x,y;
			//scanf("%c %d %d", &chr, &x, &y);
			cin >> chr >> x >> y;
			if( chr == 'A' )
				A(x,y);
			else
				B(x,y);
		}

		vector<int> a;
		a.push_back(0);
		int num = n[0].next;
		int k = 0;
		vector<int>::iterator it;
		while( num <= N ) {
			if( a.back() < num ) {
				a.push_back(num);
				k++;
			}
			else {
				it = lower_bound(a.begin(), a.end(), num);
				*it = num;
			}
			num = n[num].next;
		}

		int ret = N-k;
		//printf("#%d %d\n", test+1, ret);
		cout << "#" << test+1;
		cout << " " << ret << "\n";
	}
	return 0;
}