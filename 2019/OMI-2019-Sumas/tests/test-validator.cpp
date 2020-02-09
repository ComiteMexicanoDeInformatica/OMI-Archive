#include <bits/stdc++.h>
using namespace std;

int N, M, subtask;
int arr[305][305];


void fail(const string &msg){
	cerr << msg << endl;
	cout << 0 << endl;
	exit(0);
}

void success(){
	cout << 1 << endl;
	exit(0);
}

int readInt(int lo, int hi){
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

	int x;

	try {
		x = stoi(tmp);
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
		fail("unexpected character!" );
}

int readN()
{
	int ans;
	if( subtask <= 1 )
		ans = readInt( 1 , 15 );
	else if( subtask == 2 )
		ans = readInt( 1 , 30 );
	else if( subtask == 3 )
		ans = readInt( 1 , 70 );
	else
		ans = readInt( 1 , 300 );
	return ans;
}

bool chess( int a , int b )
{
	for( int i = 1; i <= N; i ++ )
		for( int j = 1; j <= M; j ++ )
		{
			int x = ( i + j ) % 2;
			if( x && arr[i][j] != a )
				return 0;
			if( ! x && arr[i][j] != b )
				return 0;
		}
	return 1;
}

int main(int argc, char *argv[]){
	if (argc < 2 || !isdigit(argv[1][0]))
		fail("invalid case name!");
	
	
	subtask = argv[1][0] - '0';
	N = readN();
	consumeChar(' ');
	M = readN();
	consumeChar('\n');
	
	for( int i = 1; i <= N; i ++ )
		for( int j = 1; j <= M; j ++ )
		{
			int x;
			if( subtask == 4 )
				x = readInt( 1 , 1000000000 );
			else if( subtask <= 2 )
				x = readInt( -1000000 , 1000000 );
			else
				x = readInt( -1000000000 , 1000000000 );
			
			if( j == M )
				consumeChar('\n');
			else
				consumeChar(' ');
			
		}
	
	for( int i = 1; i <= N; i ++ )
		for( int j = 1; j <= M; j ++ )
		{
			arr[i][j] = readInt( 0 , 1 );
			if( j == M )
				consumeChar('\n');
			else
				consumeChar(' ');
			
		}
	
	if( subtask == 5 && ( ! chess( 0 , 1 ) && ! chess( 1 , 0 ) ) )
		fail("array is not in chessboard format");
	
	
	success();
}
