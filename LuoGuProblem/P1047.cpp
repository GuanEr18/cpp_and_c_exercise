//
// Created by Zheng on 2026/4/24.
//
#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
// int main() {
//     int l,m;
//     //l length of road ,m number of region
//     while (cin>>l>>m) {
//         int number=l+1;
//         vector <int> tree(l+1,1);
//         int u,v;
//         //subway substarct length
//         for (int i=0;i<m;i++) {
//             cin>>u>>v;
//             for (int j=u;j<=v;j++) {
//                 if (tree[j]==1) {
//                     tree[j]=0;
//                     number--;
//                 }
//             }
//         }
//         cout<<number<<endl;
//     }
//     return 0;
// }
int main() {
    int l,m;
    cin>>l>>m;
    int u,v;
    vector<bool> c(l+1,false);
    for (int i=0;i<m;i++) {
        cin>>u>>v;
        for (int j=u;j<=v;j++) {
            c[j]=true;
        }
    }
    int count=0;
    for (int i=0;i<=l;i++) {
        if (c[i]==false) {
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}