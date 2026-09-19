#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int out;
    int lev;
};

int money, number;

int dp (const Node list[], int remain, int index) {
    if (index > number) {
        return 0;
    }
    
    int nottake = dp(list, remain, index + 1);
    
    int take = 0;
    if (remain >= list[index].out) {
        take = list[index].lev*list[index].out + dp(list, remain - list[index].out, index + 1);
    }
    return max(take, nottake);
}

int main () {
    
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> money >> number;
    
    Node list[number+1];
    for (int i = 1; i <= number; i++) {
        cin >> list[i].out >> list[i].lev;
    }
    cout << dp(list, money, 1) << endl;
}