#include <iostream>
using namespace std;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m,n;
    int a[10] = {0};
    while (cin>>m>>n) {
        for (int i=m;i<=n;i++) {
            int temp = i;
            while (temp) {
                int c = temp%10;
                temp/=10;
                switch (c) {
                    case 0: a[0]++; break;
                    case 1: a[1]++; break;
                    case 2: a[2]++; break;
                    case 3: a[3]++; break;
                    case 4: a[4]++; break;
                    case 5: a[5]++; break;
                    case 6: a[6]++; break;
                    case 7: a[7]++; break;
                    case 8: a[8]++; break;
                    case 9: a[9]++; break;
                }
            } 
        }
        for (int i=0;i<10;i++) {
            cout<<a[i]<<" ";
            a[i] = 0;
        }
    }
    return 0;
}