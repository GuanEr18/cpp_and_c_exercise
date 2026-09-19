#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int solu () {

}
 
int main () {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cost,der;
    vector<int> mon;
    vector<int> num;
    cin >> cost;
    int temp1, temp2;
    while (cin>>temp1>>temp2) {
        if (temp1==temp2==-1) {
            break;
        }
        mon.push_back(temp1);
        num.push_back(temp2);
    }
    cin >> der;

    int minMon=INT_MAX, maxMon=INT_MIN;
    for (int i = 0; i < mon.size();i++) {
        if (minMon>=mon[i])
            minMon = mon[i];
        if (maxMon<=mon[i])
            maxMon = mon[i];
    }
    if (cost>=minMon && cost<=maxMon) {
        
    }
}