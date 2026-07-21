#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void printList(vector<vector<int>> &a)
{
    for (int i = 0; i < 5; i++)
    {
        cout<<a[i][0]<<" "<<a[i][4]<<endl;
    }
}
int main()
{
    int n;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    vector<vector<int>> students(n, vector<int>(5,0));
    for (int i = 0; i < n; i++){
        students[i][0] = i+1;//学号
        cin>>students[i][1]>>students[i][2]>>students[i][3];
        students[i][4] = students[i][1]+students[i][2]+students[i][3];//总分
    }
    int col = 4;
    sort(students.begin(), students.end(), [](const vector<int> &a, const vector<int> &b)
    {
        if (a[4] != b[4]) return a[4] > b[4];
        if (a[1] != b[1]) return a[1] > b[1];
        return a[0] < b[0];
    });
    printList(students);
    return 0;
}
