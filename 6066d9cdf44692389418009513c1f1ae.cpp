/* ALGO: Segment Tree */
#include<cstdio>
#include<algorithm>
#include<climits>
using namespace std;

#define N 300000+5
int seg[N], add[N];

void update(int k, int l, int r, int u, int v, int value) {
	if(l > r || v < l || u > r) return;
	if(u <= l && r <= v) {
		seg[k] += value; add[k] += value;
		return;
	}
	update(k*2, l, (l+r)/2, u, v, value);
	update(k*2+1, (l+r)/2+1, r, u, v, value);
	seg[k] = max(seg[k*2], seg[k*2+1]) + add[k];
}

int get(int k, int l, int r, int u, int v) {
	if(l > r || v < l || u > r) return INT_MIN;
	if(u <= l && r <= v) return seg[k]; 
	return max(get(k*2, l, (l+r)/2, u, v), get(k*2+1, (l+r)/2+1, r, u, v)) + add[k];
}

int main() {
	int n, m; scanf("%d%d",&n,&m);
	for(int i = 0; i < m; ++i) {
		int u, v, k; scanf("%d%d%d",&u,&v,&k);
		update(1, 1, n, u, v, k);
	}
	int p; scanf("%d",&p);
	for(int i = 0; i < p; ++i) {
		int u, v; scanf("%d%d",&u,&v);
		printf("%d\n", get(1, 1, n, u, v));
	}
	return 0;
}
