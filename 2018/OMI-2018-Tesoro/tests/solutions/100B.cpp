#include "tesoro.h"
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;

int _query(int r, int c){
	static map<pii,int> cache;

	if (r <= 0 || c <= 0) return 0;

	auto x = cache.find(pii(r,c));
	if (x != cache.end())
		return x->second;

	return cache[pii(r,c)] = Preguntar(r,c);
}

int query(int ra, int rb, int ca, int cb){
	return _query(rb, cb)
	     - _query(rb, ca-1)
	     - _query(ra-1, cb)
	     + _query(ra-1, ca-1);
}

void go(int ra, int rb, int ca, int cb, int k, bool vertical){
	if (k == 0) return;

	if (ra == rb && ca == cb){
		Cavar(ra, ca);
		return;
	}

	if (ra == rb || (vertical && ca != cb)){
		int m = (ca + cb)/2;
		int l = query(ra, rb, ca, m);

		go(ra, rb, ca, m, l, !vertical);
		go(ra, rb, m+1, cb, k-l, !vertical);
	} else {
		int m = (ra + rb)/2;
		int l = query(ra, m, ca, cb);

		if (l) go(ra, m, ca, cb, l, !vertical);
		if (k-l) go(m+1, rb, ca, cb, k-l, !vertical);
	}
}

void BuscaTesoros(int n, int m, int k){
	go(1, n, 1, m, k, false);
}
