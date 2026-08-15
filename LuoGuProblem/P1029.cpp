#include <iostream>
using namespace std;

int gcd(int a, int b) {
    return b==0 ? a : gcd(b, a%b);
}
int lcm (int a,int b) {
    return a*b/gcd(a,b);
}
int main () {
    int x, y;
    cin >> x >> y;
    int temp1 = x,temp2=x*y/temp1,count=0;
    while (temp1<=y) {
        if (x==gcd(temp1,temp2) &&  y==lcm(temp1,temp2)) count++;
        temp1+=x;
        temp2=x*y/temp1;
    }
    cout << count << endl;
}