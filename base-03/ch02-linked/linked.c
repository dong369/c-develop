//
// Created by guodd on 2019/9/20.
// ˳�����Ա��ʵ��
//

#include<stdlib.h>
#include<stdio.h>

//�������Ա�ṹ���ṹ�����ͣ�
typedef struct LinerList {
    // ǿ���������*list�ŵĺ��壬��֤L->list[i]���������ʽ�������ָ������ָ������
    // �Լ�(L->list=(int*)malloc(ms*sizeof(int)))==NULL)��������
    int *list;// �����Ա�Ԫ��
    int size;// �����Ա���
    int MAXSIZE;// ��list����Ԫ�ظ���
} LIST;

// ��ʼ�����Ա�
void InitLIST(LIST *L, int ms) {
    if ((L->list = (int *) malloc(ms * sizeof(int))) == NULL) {
        printf("�ڴ�����ʧ�ܣ�\n");
        exit(1);
    }
    L->size = 0;
    L->MAXSIZE = ms;
}

// ��item�������Ա�L��rcλ��
int InsertLIST(LIST *L, int item, int rc) {
    // itemΪ��¼ֵ��rcΪ����λ��
    int i;
    // ���Ա�����
    if (L->size == L->MAXSIZE)
        return -1;
    // ����λ��Ϊ0��L->size
    if (rc < 0)
        rc = 0;
    if (rc > L->size)
        for (i = L->size - 1; i >= rc; i--)
            // L[i+1]=L[i];
            L->list[i + 1] = L->list[i];//���Ա�Ԫ�غ���
    L->list[rc] = item;
    L->size++;
    return 0;
}

// ������Ա�Ԫ��
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
        printf("������Ԫ��ֵ������0�������������");
        fflush(stdin);
        scanf("%d", &i);
        if (i == 0)break;
        printf("���������λ�ã�");
        scanf("%d", &r);
        InsertLIST(&LL, i, r - 1);
        printf("���Ա�Ϊ: ");
        OutputLIST(&LL);
    }
    return 0;
}