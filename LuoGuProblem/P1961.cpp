#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
int N;
int main ()
{
    int sumWeight=0;
    while(cin>>N)
    {
        vector<int> L(N);
        vector<int> R(N);
        vector<int> left(N);
        vector<int> right(N);
        vector<int> buttonWeight();
        for(int i=0;i<N;i++)
        {
            cin>>L[i]>>R[i]>>left[i]>>right[i];
        }
        int weight[N];
        for(int i=0;i<N;i++)
        {
            if(left[i]==0 && right[i]==0)
            {
                weight[i]=lcm(R[i],L[i])/R[i]+lcm(R[i],L[i])/L[i];
                /**
                 * 最小公倍数计算std::lcm(a,b)
                 * 最大公约数计算std::gcd(a,b)
                 */
                buttonWeight().push_back(weight[i]);
            }
            // 得出最下层天平最终重量 
        }
        // 单边没有重物的天平
        for(int i=0;i<N;i++)
        {
            if((right[i]!=0 && left[i]==0) || (right[i]==0 && left[i]!=0))
            {
                weight[i]=max(R[i],L[i])+min(R[i],L[i])*weight[i-1];
                /**
                 * 下层的wieght编号还没有确定，所以不能用weight[i-1]
                 * 要改
                 */
                sumWeight+=lcm(R[i],L[i])/min(R[i],L[i])*weight[i-1];
            }
        }
        // 两边都没有重物的天平
        for(int i=0;i<N;i++)
        {
            if(weight[i]==0)
            {

            }
        }
    }
}