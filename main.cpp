#include"seqlist.h"
int main() {
    SqList L;
    L.length = 0;
    SqList s;
    insert(L, 1, 1);
    insert(L, 2, 2);
    insert(L, 3, 5);
    insert(L, 4, 9);
    listprint(L);  
    deletet(L, 2);
    listprint(L);
    locate(L,9);
    insert(L, 4, 9);
    insert(L, 5, 9);
    insert(L, 6, 9);
    insert(L, 7, 9);
    listprint(L);
    delsame(L);
    listprint(L);
    return 0;
}