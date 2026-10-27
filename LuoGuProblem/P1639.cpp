#include <iostream>
using namespace std;
int main () {
    int a,b,x,y;
    cin >> a >> b >> x >> y;
    if (x>y) {
        swap(x,y);
    }
    if (a>b) {
        swap(a,b);
    }
    int used,notused = abs(b-a);
    if (x>=a && y<=b) {
        used = b-a-(y-x);
    }
    else if (x>=a && y>b) {
        used = x-a+(y-b);
    }
    else if (x<a && y<=b) {
        used = a-x+(b-y);
    }
    else if (x<a && y>b) {
        used = a-x+(y-b);
    }
    if (used < notused) {
        cout << used << endl;
    } else {
        cout << notused << endl;
    }
    return 0;
}
