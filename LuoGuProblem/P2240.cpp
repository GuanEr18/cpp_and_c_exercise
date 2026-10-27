#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

struct Node {
    int weight, value;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, T;
    cin >> n >> T;
    vector<Node> nodes(n);
    for (int i = 0; i < n; i++) {
        cin >> nodes[i].weight >> nodes[i].value;
    }
    sort(nodes.begin(), nodes.end(), [](const Node &a, const Node &b) {
        return (long long)a.value * b.weight > (long long)b.value * a.weight;
    });
    double sum = 0;
    for (int i = 0; i < n && T > 0; i++) {
        if (T >= nodes[i].weight) {
            sum += nodes[i].value;
            T -= nodes[i].weight;
        } else {
            sum += (double)nodes[i].value / nodes[i].weight * T;
            break;
        }
    }
    cout << fixed << setprecision(2) << sum << endl;
    return 0;
}