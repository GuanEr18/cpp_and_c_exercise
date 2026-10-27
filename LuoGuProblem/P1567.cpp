#include <iostream>
#include <vector>
using namespace std;
int main () {
    int n,count=1,maxContinution=0;
    cin>>n;
    vector<int> a(n,0);
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    for (int i=0;i<n-1;i++) {
        if (a[i]<a[i+1]) {
            count++;
        }
        else {
            maxContinution=max(maxContinution,count);
            count=1;
        }
    }
    maxContinution=max(maxContinution,count);
    cout<<maxContinution<<endl;
    return 0;
}