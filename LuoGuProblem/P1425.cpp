#include <iostream>
using namespace std;
int main () {
    int h1,h2,m1,m2;
    cin>>h1>>m1>>h2>>m2;
    if(m2<m1) {
        m2+=60;
        h2--;
    }
    cout<<h2-h1<<" "<<m2-m1;
    return 0;
}