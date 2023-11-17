#include <iostream>
using namespace std;

const int MAXSIZE = 100;  // 定义顺序表的最大容量
struct SqList {
    int data[MAXSIZE];  // 用数组存储顺序表的元素
    int length;  // 顺序表的当前长度
};
void insert(SqList& L, int i, int x);// 插入顺序表的第i个元素
void deletet(SqList& L, int i);//删除
void listprint(SqList L);//打印
int locate(SqList& L, int x);