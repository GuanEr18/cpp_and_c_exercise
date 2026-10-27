#include <iostream>
using namespace std;
// 判断是不是质数
bool isPrime(int n)
{
    if (n<2) return false;
    for (int i=2;i<n;i++)
    {
        if (n%i==0) return false;
    }
    return true;
}
void verifyGoldabch(int n)
{
    for (int i=2;i<=n/2;i++)
    {
        int j=n-i;
        if (isPrime(i)&&isPrime(j))
        {
            cout<<n<<"="<<i<<"+"<<j<<endl;
            return;
        }
    }
}
int main()
{
    int N;
    cin>>N;
    for (int i=4;i<=N;i+=2)
    {
        verifyGoldabch(i);
    }
    return 0;
}