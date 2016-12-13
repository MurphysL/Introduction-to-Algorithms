#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 255

typedef struct String{
    char c[MAX];
    int length;
}String;

int BFMatch(String *s , String *t , int pos){
    int i = pos - 1 , j = 1;
    int num = 0;
    while(i < s->length){

        if(s->c[i] == t->c[j - 1]){
            if(j == t->length){
                num += 1;
                j = 1;
            }
            ++i;
            ++j;
        }else{
            i = i - j + 2;
            j = 1;
        }
    }
    return num;
}

void initString(String *s , String *t , int *pos){
    printf("主串:");
    scanf("%s" , s->c);
    s->length = strlen(s->c);

    printf("\n子串:");
    scanf("%s" , t->c);
    t->length = strlen(t->c);

    printf("\n开始的位置:");
    scanf("%d" , pos);
}

int main(){
    String *s = (String *)malloc(sizeof(String));
    String *t = (String *)malloc(sizeof(String));
    int pos;
    initString(s , t , &pos);

    printf("%d" , BFMatch(s , t , pos));
    return 0;
}
