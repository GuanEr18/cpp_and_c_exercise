#include <iostream>
using namespace std;
int main()
{
    int now=0,storage=0;
    int a[13];
    for(int i=1;i<=12;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=12;i++)
    {
        now+=300;
        now-=a[i];
        if(now>=100)
        {
            while(now>=100)
            {
                now-=100;
                storage+=100;
            }
        }
        if(now<0)
        {
            cout<<"-"<<i<<endl;
            return 0;
        }
    }
    cout<<now+storage*1.2<<endl;
    return 0;
}