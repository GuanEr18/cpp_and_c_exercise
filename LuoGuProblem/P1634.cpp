#include <iostream>
using namespace std;

int main() {
    unsigned long long n,x,count=1;
    cin >> x >> n;
    while(n--){
        count =count+(count*x);
    }
    cout << count << endl;
}