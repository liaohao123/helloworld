#include "seqlist.h"
void insert(SqList& L, int i, int x)// 在顺序表的第i个元素之前插入一个新元素x
{
    if (i < 1 || i > L.length + 1) {
        cout << "插入位置不合法" << endl;
        return;
    }
    if (L.length >= MAXSIZE) {
        cout << "顺序表已满，无法插入" << endl;
        return;
    }
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];  // 元素后移
    }
    L.data[i - 1] = x;  // 插入新元素
    L.length++;  // 长度加1
}
// 删除顺序表的第i个元素
void deletet(SqList& L, int i) {
    if (i < 1 || i > L.length) {
        cout << "删除位置不合法" << endl;
        return;
    }
    for (int j = i; j < L.length; j++) {
        L.data[j - 1] = L.data[j];  // 元素前移
    }
    L.length--;  // 长度减1
}
// 输出顺序表
void listprint(SqList L) {
    for (int i = 0; i < L.length; i++) {
        cout << L.data[i] << " ";
    }
    cout << endl;
}
int locate(SqList& L, int x) {
    for (int i = L.length; i >=1; i--) {
        int a = 0;
        if (L.data[i] == x) {
            a = i;
            cout << a << endl;
        }
        return a;
    }
}
void Inverse(SqList& L) {
    int i, temp;
    for (i = 0; i < L.length / 2; i++) {
        temp = L.data[i];
        L.data[i] = L.data[L.length - 1 - i];
        L.data[L.length - 1 - i] = temp;
    }
}
void delsame(SqList& L) {
    for (int i = 0; i <= L.length; i++) {
        int a = L.data[i];
        for (int j = i + 1; j <= L.length; j++) {
            if (L.data[j] == a) {
                deletet(L, j);
            }
        }


    }
}