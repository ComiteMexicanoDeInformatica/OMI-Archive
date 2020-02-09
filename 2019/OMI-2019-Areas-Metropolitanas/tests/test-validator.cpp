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

long long readN()
{
    long long ans;
    if( subtask <= 2 )
        ans = readInt( 1 , 50 );
    else
        ans = readInt( 1 , 250 );
    return ans;
}

long long readK()
{
    long long ans;
    if( subtask == 2 )
        ans = readInt( 1 , 1 );
    else if( subtask == 3 )
        ans = readInt( 3 , 3 );
    else 
        ans = readInt( 1 , min( N , M ) );
    return ans;
}

long long readQ()
{
    long long ans;
    if( subtask == 1 )
        ans = readInt( 0 , 0 );
    else if( subtask == 4 )
        ans = readInt( 0 , 250 );
    else
        ans = readInt( 0 , 20000 );
    return ans;
}


int main(int argc, char *argv[]){
	if (argc < 2 || !isdigit(argv[1][0]))
		fail("invalid case name!");
	
	
	subtask = argv[1][0] - '0';
    
    N = readN();
    consumeChar(' ');
    M = readN();
    consumeChar(' ');
    K = readK();
	consumeChar(' ');
	LIM = readInt( 1 , 1000000000000000LL );
	consumeChar('\n');
	for( int i = 1; i <= N; i ++ )
        for( int j = 1; j <= M; j ++ )
	    {
	        long long x;
	        x = readInt( 1 , 1000000LL );
	        if( j == M )
	            consumeChar('\n');
	        else
	            consumeChar(' ');
	    }
	Q = readQ();
	consumeChar('\n');
	while( Q -- )
	{
	    long long i, j, x, t;
	    i = readInt( 1 , N );
	    consumeChar(' ');
	    j = readInt( 1 , M );
	    consumeChar(' ');
	    if( subtask == 6 )
	        x = readInt( -1000000LL , 1000000LL );
	    else
	        x = readInt( 1LL , 1000000LL );
	    consumeChar(' ');
	    t = readInt( 1 , 1000000LL );
	    consumeChar('\n');
	}
	success();
}
