#include <iostream>
#include <string> 
#include <algorithm>
using namespace std;

long long int decode(string s){	
	long long int ret = 0;
	long long int pot = 1, b = 26;
	
	for(int i = s.size() - 1; i >= 0; i--){
		ret += pot * ( pot > 1 ? ( s[i] - 'A' + 1) : (s[i] - 'A') ) ;
		pot *= b;
	}
	
	return ret + 1LL;
}

string encode(long long int n){
	long long b = 26;
	string ret;
	
	while(n){
		long long num = n % b;
		if (num == 0) num = 26;
		
		n /= b;
		if(num == 26) n--;
		
		ret += char ( num + (long long)('A') - 1LL);		
	}
	
	reverse(ret.begin(), ret.end());
	return ret;
}

int main() {
	
	int op;
	cin >> op;
	
	if(op){
		string s;
		cin >> s;
		cout << decode(s) << "\n"; 
	} else {
		long long n;
		cin >> n;
		cout << encode(n) << "\n";
	}
	
	return 0;
}