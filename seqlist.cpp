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
        if (L.data[i] == x) {
            cout << i-1 << endl;
            return i-1;

        }cout << "������" << endl;
        return 0;
  
    }
}