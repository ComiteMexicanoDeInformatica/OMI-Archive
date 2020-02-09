#include <bits/stdc++.h>
using namespace std;

long long subtask;
long long N, M, Q, K, LIM;

void fail(const string &msg){
	cerr << msg << endl;
	cout << 0 << endl;
	exit(0);
}

void success(){
	cout << 1 << endl;
	exit(0);
}

long long readInt( long long lo ,  long long hi ) {
	string tmp;
	char c;
	while (c = cin.get()){
		if (isdigit(c))
			tmp += c;
		else if( c == '-' && ! tmp.size() )
			tmp += '-';
		else break;
	}

	cin.putback(c);

	long long x;

	try {
		x = stoll(tmp);
	} catch (out_of_range e) {
		fail("integer overflow: " + tmp);
	}

	if (x < lo || x > hi) {
		fail("out of bounds: " + tmp);
	}

	return x;
}

void consumeChar(char c){
	char x = cin.get();

	if (x != c)
		fail("unexpected character!");
}

int main(int argc, char *argv[]){
	if (argc < 2 || !isdigit(argv[1][0]))
		fail("invalid case name!");
	
	N = readInt(1, 100000);
	consumeChar('\n');
	for ( int i = 1; i <= N; i++ )  {
		readInt(1, 1000000000LL);
		if( i == N )
			consumeChar('\n');
		else
			consumeChar(' ');
	}
	success();
}
