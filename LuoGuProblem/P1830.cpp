#include <iostream>
#include <vector>
using namespace std;
int main () {
    int n,m,x,y;
    cin >> n >> m >> x >> y;
    vector<vector<pair<int, int>> > arr(n, vector<pair<int, int>>(m, {0, 0}));
    for (int k = 1; k <= x; k++) {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = x1-1; i < x2; i++) {
            for (int j = y1-1; j < y2; j++) {
                arr[i][j].first++;
                arr[i][j].second=k;
            }
        }
    }
    for (int i = 1; i <= y; i++) {
        int x,y;
        cin >> x >> y;
        if (arr[x-1][y-1].first == 0) {
            cout<< "N" << endl;
        }
        else {
            cout << "Y" << " " << arr[x-1][y-1].first << " ";
            cout << arr[x-1][y-1].second << endl;
        }
    }
    return 0;
}