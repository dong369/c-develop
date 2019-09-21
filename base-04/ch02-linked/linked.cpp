//
// Created by guodd on 2019/9/20.
//

#include <iostream>

struct LinerList {
//强化理解这里*list号的含义，保证L->list[i]不报错：表达式必须包含指向对象的指针类型//以及(L->list=(int*)malloc(ms*sizeof(int)))==NULL)正常分配
    int *list;//存线性表元素
    int size;//存线性表长度
    int MAXSIZE;//存list数组元素个数
};
typedef struct LinerList LIST;

void test(LIST &L) {
    L.list = 0;
    L.MAXSIZE = 0;
}

int main(void) {
    std::cout << "Hello World" << std::endl;
    return 0;
}

