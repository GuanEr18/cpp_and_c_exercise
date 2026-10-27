#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main () {
    int h[2],m[2],s[2];
    char c1,c2;
    cin>>h[0]>>c1>>m[0]>>c2>>s[0];
    cin>>h[1]>>c1>>m[1]>>c2>>s[1];
    int x;
    cin>>x;
    long long t1 = h[0]*3600+m[0]*60+s[0];
    long long t2 = h[1]*3600+m[1]*60+s[1];
    long long d;
    d=t2-t1;
    d=d*x;
    cout<<d<<endl;
}