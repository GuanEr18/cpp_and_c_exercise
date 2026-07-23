#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

struct balance
{
    int L;
    int R;
    int left;
    int right;
    // right and left在'0'时候表示挂砝码
};
// u是第'u'位的天平平衡时要的最小重量
long long DFS(int u,const vector<balance>& tree) 
{
    if (u==0)
    {
        return 1;
        // 这个是特殊情况
    }
    long long weightLeft=DFS(tree[u].left,tree);
    long long weightRight=DFS(tree[u].right,tree);
    // 
    long long baseLeft=weightLeft*tree[u].L;
    long long baseRight=weightRight*tree[u].R;
    // 两边力矩的最小公倍数
    long long liJv=lcm(baseLeft,baseRight);
    long long actualWeight=liJv/tree[u].L+liJv/tree[u].R;
    return actualWeight;
    // 返回这个天平平衡时的最小重量='u'
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N,sumWeight=0;
    while(cin>>N)
    {
        vector<balance> tree(N+1);
        // 每个天平被挂了几个节点
        vector<int> degree(N+1,0);
        for(int i=1;i<=N;i++)
        {
            cin>>tree[i].L>>tree[i].R>>tree[i].left>>tree[i].right;
            if(tree[i].left!=0)
            {
                degree[tree[i].left]++;
            }
            if(tree[i].right!=0)
            {
                degree[tree[i].right]++;
            }
        }
        // 找到根节点
        int root;
        for(int i=1;i<=N;i++)
        {
            if(degree[i]==0)
            {
                root=i;
                break;
            }
        }
        long long sumWeight=DFS(root,tree);
        cout<<sumWeight<<endl;
    }
    return 0;
}