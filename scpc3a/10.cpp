#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

string s;
vector<int> a;
bool checkOpen(int i)
{
	if( s[i] == '(' || s[i] == '{' || s[i] == '[' )
		return true;
	return false;
}

void search()
{
	int ret = 0;
	int len = 0;
	vector<int> st;
	for(int i=0; i<s.size(); i++) {
		if( checkOpen(i) )
			st.push_back(i);
		else {
			if( st.size() == 0 )
				continue;
			int size = st.size();
			if( s[st[size-1]] == '(' && s[i] == ')' ) {
				a[st[size-1]] = 1;
				a[i] = 1;
			}
			else if( s[st[size-1]] == '{' && s[i] == '}' ) {
				a[st[size-1]] = 1;
				a[i] = 1;
			}
			else if( s[st[size-1]] == '[' && s[i] == ']' ) {
				a[st[size-1]] = 1;
				a[i] = 1;
			}
			st.pop_back();
		}
	}
}

int main(void)
{
	int Case;
	scanf("%d", &Case);
	for(int test=0; test<Case; test++) {
		cin >> s;
		a = vector<int>(s.size(),0);
		search();
		int ret = 0;
		int sum = 0;
		for(int i=0; i<a.size(); i++) {
			if( a[i] )
				sum++;
			if( !a[i] ) {
				ret = max(ret, sum);
				sum = 0;
			}
		}
		ret = max(ret, sum);
		printf("Case #%d\n%d\n", test+1, ret);
 	}
	return 0;
}