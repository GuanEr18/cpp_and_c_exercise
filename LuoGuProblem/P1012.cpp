#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    /**
     * 这个想法在输入 1212 和12 的时候会陷入死循环
     */
    // sort(a.begin(), a.end(), [](const string &s1, const string &s2)
    //      {
    //         int i=0;
    //         while (i % s1.length() < s1.length() && i % s2.length()< s2.length())
    //         {
    //             if (s1[i]==s2[i])
    //                 i++;
    //             else
    //                 return s1[i] > s2[i];
    //         } });
    sort(a.begin(), a.end(), [](const string &s1, const string &s2)
         {
             return s1 + s2 > s2 + s1; // 降序，取最大拼接值
         });
    for (int i = 0; i < n; i++)
    {
        cout << a[i];
    }
}