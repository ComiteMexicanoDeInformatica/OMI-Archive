#include <iostream>
#include <string>
#include <vector>
using namespace std;

char* convierte(__int128 n,int cont){
	char *ret = new char[cont];
	__int128 base = 26;
	vector<int> res(cont);
	for(int i = 0; i < cont ; i ++){
		res[i] = int(n%base);
		n /= base;
	}
	for(int i = cont -1 ; i >= 0 ; i--)
		ret[cont-(i+1)] = char(res[i]+'A');
	return ret;
}

char* encode(long long int V){
	int cont = 1;
	__int128 n = V, base = 26, pot = 26;

	while(pot < n){
		n -= pot;
		pot *= base;
		cont++;
	}

	return convierte(--n,cont);

}

long long int decode(const char s[]){
	int n = 0;
	for( ; s[n] ; n ++);
	long long int ret = 0 , pot = 1 , base = 26;

	for(int i = 0; i < n-1 ; i ++){
		pot *= base;
		ret += pot;
	}

	pot = 1;
	for(int i = n-1; i >= 0 ; i --){
		ret += pot*(s[i]-'A');
		if(i) pot *= base;
	}

	return ret+1LL;

}

int main() {

	int op;
	cin >> op;

	if(op){
		string s;
		cin >> s;
		cout << decode(s.c_str()) << "\n";
	} else {
		long long n;
		cin >> n;
		cout << encode(n) << "\n";
	}

	return 0;
}
