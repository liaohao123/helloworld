#include "seqlist.h"
void insert(SqList& L, int i, int x)// ��˳���ĵ�i��Ԫ��֮ǰ����һ����Ԫ��x
{
    if (i < 1 || i > L.length + 1) {
        cout << "����λ�ò��Ϸ�" << endl;
        return;
    }
    if (L.length >= MAXSIZE) {
        cout << "˳����������޷�����" << endl;
        return;
    }
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];  // Ԫ�غ���
    }
    L.data[i - 1] = x;  // ������Ԫ��
    L.length++;  // ���ȼ�1
}
// ɾ��˳���ĵ�i��Ԫ��
void deletet(SqList& L, int i) {
    if (i < 1 || i > L.length) {
        cout << "ɾ��λ�ò��Ϸ�" << endl;
        return;
    }
    for (int j = i; j < L.length; j++) {
        L.data[j - 1] = L.data[j];  // Ԫ��ǰ��
    }
    L.length--;  // ���ȼ�1
}
// ���˳���
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