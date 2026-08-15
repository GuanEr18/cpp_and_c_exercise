#include <iostream>
using namespace std;
int main () {
    int m, n,sum=0;
    cin >> n >> m;
    for(int i=0;i<m;i++) {
		cout<<(n-sum)/(m-i)<<" ";
		sum+=(n-sum)/(m-i);
	}
}