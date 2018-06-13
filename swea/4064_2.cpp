#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

int N, S;
int psum[100001];
map<int, int> m;

void bis(int pivot)
{
    int l = 0;
    int r = min(N - pivot, pivot);
    int mid = (l + r) / 2;
    int ans = 0;
    while (l <= r) {
        mid = (l + r) / 2;
        int sl = psum[pivot] - psum[pivot - mid];
        int sr = psum[pivot + mid] - psum[pivot];
        if (sl > S || sr > S)
            r = mid - 1;
        else {
            ans = mid;
            l = mid + 1;
        }
    }
    if (!ans)
        return;
    if (m.count(pivot - ans)) 
        m[pivot - ans] = max(m[pivot - ans], ans);
    else 
        m[pivot - ans] = ans;
}

int main(void)
{
    int Case;
    scanf("%d", &Case);
    for(int test=0; test<Case; test++) {
        memset(psum, 0, sizeof(psum));
        m.clear();
        scanf("%d %d", &N, &S);
        for(int i=1; i<=N; i++) {
            scanf("%d", &psum[i]);
            psum[i] += psum[i-1];
        }
        for(int i=1; i<=N; i++)
            bis(i);
        int prev = 0;
        map<int,int>::iterator it = m.begin();

        printf("#%d", test+1);
        for (int i=0; i<N; i++) {
            if (it == m.end()) {
                printf(" %d", max(--prev, 0) * 2);
                continue;
            }
            prev = max(prev-1, 0);
            if (i == (*it).first) 
                prev = max(prev, (*it++).second);
            printf(" %d", prev * 2);
        }
        printf("\n");
    }
    return 0;
}