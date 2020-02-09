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
	if (ra > rb || ca > cb) return 0;

	return _query(rb, cb)
	     - _query(rb, ca-1)
	     - _query(ra-1, cb)
	     + _query(ra-1, ca-1);
}

void go(int ra, int rb, int ca, int cb, int k){
	if (k == 0 || ra > rb || ca > cb) return;

	if (ra == rb && ca == cb){
		Cavar(ra, ca);
		return;
	}

	int mr = (ra + rb)/2;
	int mc = (ca + cb)/2;

	int rr[] = {ra, mr+1, rb+1};
	int cc[] = {ca, mc+1, cb+1};
	int soFar = 0;

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++){
			int cnt;

			if (!(i && j))
				soFar += cnt = query(rr[i], rr[i+1]-1, cc[j], cc[j+1]-1);
			else
				cnt = k - soFar;

			go(rr[i], rr[i+1]-1, cc[j], cc[j+1]-1, cnt);
		}
}

void BuscaTesoros(int n, int m, int k){
	go(1, n, 1, m, k);
}
