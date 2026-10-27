#include <iostream>
using namespace std;

int change(int n)
{
    int count=0;
    while(n>0)
    {
        if(n%10==2)
        {
            count++;
        }
        n/=10;
    }
    return count;
}
int main()
{
    int a,b;
    cin>>a>>b;
    int count=0;
    for(int i=a;i<=b;i++)
    {
        count+=change(i);       
    }
    cout<<count<<endl;
    return 0;
}