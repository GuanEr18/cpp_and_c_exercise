#include <iostream>
using namespace std;
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    int x,y;
    while(cin>>x>>y) {
        if (x>y) swap(x,y);
        int shape1=0,shape2=0;
    
        shape1+=x*y;
        for (int i=2;i<=x;i++) {
            shape1+=(x-i+1)*(y-i+1);
        }

        for (int i=1;i<=x;i++) {
            for (int j=1;j<=y;j++) {
                if(i==j) continue;
                shape2+=(x-i+1)*(y-j+1);
            }
        }

        cout<<shape1<<" "<<shape2;
    }
}
