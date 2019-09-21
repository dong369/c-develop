//
// Created by guodd on 2019/9/20.
// 顺序线性表的实现
//

#include<stdlib.h>
#include<stdio.h>

//定义线性表结构（结构体类型）
typedef struct LinerList {
    // 强化理解这里*list号的含义，保证L->list[i]不报错：表达式必须包含指向对象的指针类型
    // 以及(L->list=(int*)malloc(ms*sizeof(int)))==NULL)正常分配
    int *list;// 存线性表元素
    int size;// 存线性表长度
    int MAXSIZE;// 存list数组元素个数
} LIST;

// 初始化线性表
void InitLIST(LIST *L, int ms) {
    if ((L->list = (int *) malloc(ms * sizeof(int))) == NULL) {
        printf("内存申请失败！\n");
        exit(1);
    }
    L->size = 0;
    L->MAXSIZE = ms;
}

// 将item插入线性表L的rc位置
int InsertLIST(LIST *L, int item, int rc) {
    // item为记录值，rc为插入位置
    int i;
    // 线性表已满
    if (L->size == L->MAXSIZE)
        return -1;
    // 插入位置为0到L->size
    if (rc < 0)
        rc = 0;
    if (rc > L->size)
        for (i = L->size - 1; i >= rc; i--)
            // L[i+1]=L[i];
            L->list[i + 1] = L->list[i];//线性表元素后移
    L->list[rc] = item;
    L->size++;
    return 0;
}

// 输出线性表元素
void OutputLIST(LIST *L) {
    int i;
    for (i = 0; i < L->size; i++)
        printf("%d ", L->list[i]);
    printf("\n");
}


int main() {
    LIST LL;
    int i, r;
    InitLIST(&LL, 10);
    printf("LIST addr=%p\tsize=%d\tMaxSize=%d\n", LL.list, LL.size, LL.MAXSIZE);
    OutputLIST(&LL);
    while (1) {
        printf("请输入元素值，输入0结束插入操作：");
        fflush(stdin);
        scanf("%d", &i);
        if (i == 0)break;
        printf("请输入插入位置：");
        scanf("%d", &r);
        InsertLIST(&LL, i, r - 1);
        printf("线性表为: ");
        OutputLIST(&LL);
    }
    return 0;
}