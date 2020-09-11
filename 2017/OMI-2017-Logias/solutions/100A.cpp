#include<iostream>
int main(){
	long long n,m;
	std::cin>>n>>m;
	std::cout<<(m*(n/m-1)+(n%m)*2)*(n/m)/2<<' '<<((n-m+1)*(n-m)/2)<<'\n';
}
