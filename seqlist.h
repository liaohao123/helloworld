#include <iostream>
using namespace std;

const int MAXSIZE = 100;  // ����˳�����������
struct SqList {
    int data[MAXSIZE];  // ������洢˳����Ԫ��
    int length;  // ˳���ĵ�ǰ����
};
void insert(SqList& L, int i, int x);// ����˳���ĵ�i��Ԫ��
void deletet(SqList& L, int i);//ɾ��
void listprint(SqList L);//��ӡ
int locate(SqList& L, int x);