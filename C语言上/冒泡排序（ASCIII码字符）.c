#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void bubbleSort(int len, char str[100]) {
    char temp;
    //外层循环
    for(int i=0;i<len-1;i++) {
    //从第一位开始比较
        //内层循环
        for(int j=0;j<len-i-1;j++) {
        //由第0位开始向下比较
            //换位
            if(str[j]>str[j+1]) {
                temp = str[j];
                str[j] = str[j+1];
                str[j+1] = temp;
            }
        }
    }
}
int main (void) {
    char str [100];
    while(scanf("%s",&str) != EOF) {
        int len = strlen(str);
        bubbleSort(len,str);
        printf("%s\n",str);
    }
    return 0;
}
//为什么用 void 更合适。冒泡排序是“原地排序”：函数通
//过参数拿到数组首地址，直接交换元素，排序结果就写回
//原数组。调用者在传参后就已经“拥有”排序后的数据，
//无需再通过返回值把数组再“带回来”。
//用 void 语义最清晰：排序是过程，结果在原地