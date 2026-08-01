#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int daily_unhappy = 0; // 记录当前的不高兴程度（会持续到第二天）
    int total_sum = 0;     // 记录n天不高兴程度的总和
    
    for (int i = 0; i < n; i++) {
        int school, extra;
        cin >> school >> extra;
        
        // 当天产生的不高兴度（上学+课外班-8）累加到持续的不高兴度中
        daily_unhappy += (school + extra - 8);
        
        // 将每一天的不高兴度加入总和
        total_sum += daily_unhappy;
    }
    
    cout << total_sum << endl;
    return 0;
}
