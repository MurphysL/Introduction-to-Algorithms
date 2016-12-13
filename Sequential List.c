#include <stdio.h>

#define MAX 100

typedef struct{
    int num[MAX];
    int length;
}SList;

void initList(SList *slist){
    int i = 0;
    printf("��ʼ��5λ˳���:\n");
    for(i = 0 ; i < 5 ; i++){
        scanf("%d" , &slist->num[i]);
    }

    slist->length = 5;
}

int GetElem(SList *slist , int pos){
    if(pos > slist->length || pos <= 0){
        return -1;
    }else{
        return slist->num[pos - 1];
    }
}

int LocateElem(SList *slist , int elem){
    int i;

    for(i  = 0 ; i < slist->length ; i++){
        if(slist->num[i] == elem){
            return i + 1;
        }
    }
    return -1;
}

void InsertList(SList * slist , int elem , int pos){
    int i;
    if(pos <= 0){
        printf("λ���������");
    }else{
        for(i = slist->length - 1 ; i >= pos - 1 ; i --){
            slist->num[i + 1] = slist->num[i];
        }
        slist->num[i + 1] = elem;
        slist->length += 1;
    }
}

void DeleteList(SList *slist , int pos){
    int i;
    if(pos <= 0 || slist->length < pos){
        printf("��������ȷλ��");
    }else{
        for(i = pos - 1 ; i < slist->length - 1 ; i ++){
            slist->num[i] = slist->num[i + 1];
        }
        slist->length -= 1;
    }
}

int main(){
    int i , pos , n;

    SList *slist = (SList *)malloc(sizeof(SList));
    initList(slist);

    printf("������Ҫ��ѯ��λ��:");
    scanf("%d" , &pos);
    i = GetElem(slist , pos);
    if(i == -1){
        printf("λ���������!");
    }else{
        printf("%d" , i);
    }

    printf("\n������Ҫ��ѯ��ֵ:");
    scanf("%d" , &n);
    if(-1 == (i = LocateElem(slist , n))){
        printf("���޴�ֵ%d" , i);
    }else{
        printf("λ��:%d" , i);
    }

    printf("\n���������ֵ��λ��,�Կո����:");
    scanf("%d %d" , &n , &pos);
    InsertList(slist , n , pos);

    for(i = 0 ;i < slist->length ; i ++){
        printf("%d" , slist->num[i]);
    }


    printf("\n������Ҫɾ����λ��:");
    scanf("%d" , &pos);
    DeleteList(slist , pos);

    for(i = 0 ;i < slist->length ; i ++){
        printf("%d" , slist->num[i]);
    }

    return 0;
}
