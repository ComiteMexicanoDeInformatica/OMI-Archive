#include <iostream>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int A[100000];

int main(){
	optimizar_io
	
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> A[i];
	
	int ans = 0;
	for(int i = 0; i < n; i++){
		int j = i + 1;
		
		while(j < n && A[j] < A[j - 1])
			j++;
		
		ans = max(ans, j - i);
	}
	
	cout << ans << "\n";
	
	return 0;
	
}