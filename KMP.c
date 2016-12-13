#include <stdio.h>
#include <string.h>
#define MAX 100
typedef struct String {
    char c[MAX];
}String ;

void initString (String *s , String *s1){
    printf("����:");
    scanf("%s" , s->c);
    printf("�Ӵ�:");
    scanf("%s" , s1->c);
}

void initNext(String *s1 , int *next){
    int length = strlen(s1->c);
    int j = 0;
    int k = -1;
    next[0] = -1;
    while(j < length - 1){
        if(k = -1 || s1->c[k] == s1->c[j]){
            next[++j] = ++k;
        }else{
            k = next[k];
        }
    }
}

int KMPMatch(String *s , String *s1 , int *next){
    int ls = strlen(s->c);
    int ls1 = strlen(s1->c);
    int i = 0 , j = 0;
    while(i < ls && j < ls1){
        if(next[j] = -1 || s1->c[j] == s->c[i]){
            ++i;
            ++j;
        }else{
            j = next[j];
        }

    }

     if (j == ls1) {

        return (i + 1);

     } else {

        return -1;

     }
}

int main(){
    String * s = (String *)malloc(sizeof(String));
    String * s1 = (String *)malloc(sizeof(String));
    int next[MAX];
    int num = 0;

    initString (s , s1);

    initNext(s1 , next);

    num = KMPMatch(s , s1 , next);

    if(num == -1){
        printf("δƥ�䵽���ַ���");
    }else{
        printf("��ƥ�䵽���ַ���,��ʼλ��Ϊ%d" , num);
    }

    return 0;
}
