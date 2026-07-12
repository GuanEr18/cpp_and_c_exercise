//
// Created by Zheng on 2026/5/6.
//
#include <iostream>
#include <vector>
using namespace std;

int V,n,minRemain;

//index:当前处理第几个物体。currentVolume:当前塞进去的物体的体积
void DFS(int index,int currentVolume,const vector<int>& volume) {
    if(index==n) {
        minRemain = min(minRemain,V-currentVolume);
        return;
        //这里的return没有返回‘0’所以返回值为void的方法只能这样子
        //返回，在这个方法中表示递归方法到来了尽头要返回‘n-1’层
        //执行之前没有执行的另一个函数
    }
    //不选当前这个物体，直接看下一个
    DFS(index+1,currentVolume,volume);
    //选当前这个物体
    if(currentVolume+volume[index] <= V) {
        currentVolume = currentVolume+volume[index];
        DFS(index+1,currentVolume,volume);
    }
}

/** 递归并不是“瞬间移动”，而是一层一层的“嵌套”。
    一步步往回走是对的，但重点在于：每一层都保留了它当时执行到哪里的“进度条”。

    模拟运行：为什么能执行“没跑过”的函数？
    任务 A：判断是否到终点（if index == n）。
    任务 B：执行 DFS(index + 1, currentVolume, ...)（左分支：不选）。
    任务 C：执行 DFS(index + 1, currentVolume + volume[index], ...)（右分支：选）。

    第一层 DFS(0, 0) 启动：
    执行任务 A：没到终点。
    执行任务 B：调用 DFS(1, 0)。【注意：此时第一层的任务 C 还没做，正在排队等待】

    第二层 DFS(1, 0) 启动：
    执行任务 A：没到终点。
    执行任务 B：调用 DFS(2, 0)。【注意：此时第二层的任务 C 还没做，正在排队】

    第三层 DFS(2, 0) 启动：
    执行任务 A：index == 2！更新答案，执行 return;。
    重点： 这个 return 确实只回到了直接调用它的地方，即第二层。

    回到第二层 DFS(1, 0)：
    刚才第二层执行完了任务 B，现在程序自然而然地向下走，开始执行刚才没做的任务 C（选物品 1）。
    任务 C 调用 DFS(2, 7)。

    第四层 DFS(2, 7) 启动：(另外一种可能性)
    执行任务 A：index == 2！更新答案，执行 return;。

    回到第二层 DFS(1, 0)：
    此时第二层任务 A、B、C 全部做完了。
    第二层函数执行完毕，自动触发隐含的 return，回到第一层。

    回到第一层 DFS(0, 0)：
    刚才第一层只执行完了任务 B，现在它发现自己也有个任务 C（选物品 0）没做！
    于是第一层开始执行 DFS(1, 4)。
 */
int main() {
    while(cin>>V>>n) {
        vector<int> volume(n);
        for(int i=0;i<n;i++) {
            cin>>volume[i];
        }
        minRemain = V;
        //从第0个物体开始，目前占用的体积是0
        DFS(0,0,volume);
        cout<<minRemain<<endl;
    }
}