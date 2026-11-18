// P1076 洛谷
#include <iostream>
#include <vector>
using namespace std;

const int mod = 20123;
int n, m;
vector<vector<pair<int, int>>> a;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    a.resize(n, vector<pair<int, int>>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j].first >> a[i][j].second;
        }
    }
    int in;
    cin >> in;
    long long ans = 0;
    for(int i=0;i<n;i++) {
        ans = (ans + a[i][in].second) % mod;
        int need = a[i][in].second % m;
        if(need==0)
            need = a[i][in].second;

        int found = 0;
        while(true) {
            if(a[i][in].first==1) {
                ++found;
                if(found==need) 
                    break;
            }
            in = (in + 1) % m;
            // 是一个环
        }
    }
    cout << ans << endl;
}