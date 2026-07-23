#include <iostream>
using namespace std;
int main ()
{
    int K;
    cin >> K;
    int count = 0;
    for (int i = 10000; i <= 30000; i++)
    {
        int a=i/100;
        int b=i%1000;
        int c=i/10%1000;
        if (a%K==0 && b%K==0 && c%K==0)
        {
            count++;
            cout << i << endl;
        }
    }
    if (count==0)
    {
        cout << "No" << endl;
    }
    return 0;
}