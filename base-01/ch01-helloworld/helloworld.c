//
// Created by guodd on 2019/6/25.
//
#include "stdio.h"

void test() {
    printf("test");
}

int main() {
    int var1;
    char var2[10];

    printf("var1 �����ĵ�ַ�� %p\n", &var1);
    printf("var2 �����ĵ�ַ�� %p\n", &var2);
    
    printf("hello world!\n");
    test();
    return 0;
}
