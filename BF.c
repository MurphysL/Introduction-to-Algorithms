#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 255

/**
 * Brute-Force
 *
 * best T=O(m+n)
 * worst T=O(m*n)
 */

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

void initString(String *s , String *t){
    printf("Primary String:");
    scanf("%s" , s->c);
    s->length = strlen(s->c);

    printf("\nSubstring:");
    scanf("%s" , t->c);
    t->length = strlen(t->c);
}

int main(){
    String *s = (String *)malloc(sizeof(String));
    String *t = (String *)malloc(sizeof(String));
    initString(s , t);

    int pos;
    printf("\nLocation:");
    scanf("%d" , &pos);

    printf("\ntimes:%d" , BFMatch(s , t , pos));
    return 0;
}
