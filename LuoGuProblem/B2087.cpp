#include<iostream>
using namespace std;
int main ()
{
    int n;
    while(cin>>n)
    {
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int temp,count=0;
        cin>>temp;
        for(int i=0;i<n;i++)
        {
            if(a[i]==temp)
            {
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}