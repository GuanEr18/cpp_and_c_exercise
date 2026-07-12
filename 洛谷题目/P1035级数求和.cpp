#include<iostream>
using namespace std;
int main()
{
    int k,n;
    while(cin>>k)
    {
        double sum=0.;
        int n=1;
        while(k>=sum) 
        {
            sum+=1.0/n;
            n++;
        }
        cout<<n<<endl;
    }
    return 0;
}