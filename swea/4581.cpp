#include <iostream>
#include <cstdio>

using namespace std;

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		string s;
		cin >> s;
		int a = 0;
		int b = s.size()-1;

		string ret;
		while( a <= b ) {
			if( s[a] > s[b] ) {
				ret += s[b];
				b--;
			}
			else if( s[a] < s[b] ) {
				ret += s[a];
				a++;
			}
			else {
				int aa = a;
				int bb = b;
				while( s[aa] == s[bb] && aa+1 < bb ) {
					aa++;
					bb--;
				}
				if( s[aa] < s[bb] ) {
					int aaa = a;
					while( s[a] == s[aaa] )
						aaa++;
					while( a < aaa ) {
						ret += s[a];
						a++;
					}
				}
				else {
					int bbb = b;
					while( s[b] == s[bbb] )
						bbb--;
					while( b > bbb ) {
						ret += s[b];
						b--;
					}
				}
			}
		}

		printf("#%d %s\n", test+1, ret.c_str());
	}
	return 0;
}