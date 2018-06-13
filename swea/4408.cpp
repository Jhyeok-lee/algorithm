#include <iostream>

using namespace std;

class M {
public:
	int u,v;
	M(int _u, int _v)
	{
		u = _u;
		v = _v;
	}
};

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		int N;
		scanf("%d", &N);
		vector<M> m;
		for(int i=0; i<N; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			if( u > v )
				swap(u,v);
			m.push_back(M(u,v));
		}
		int ret = 0;
		while( m.size() ) {
			int u = m[0].u;
			int v = m[0].v;
			vector<M>::iterator it;
			for(it=m.begin(); it!=m.end();) {
				if( (u <= it->u && it->u <= v) ||
					(u <= it->v && it->v <= v) )
					it++;
				else
					m.erase(it);
			}
			m.erase(m.begin());
			ret++;
		}
		printf("#%d %d\n", test+1, ret);
	}
	return 0;
}