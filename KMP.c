#include <stdio.h>
#include <string.h>
#define MAX 100

/**
 * KMP
 * http://www.ruanyifeng.com/blog/2013/05/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm.html
 * http://www.cnblogs.com/yjiyjige/p/3263858.html
 *
 */
typedef struct String {
    char c[MAX];
    int length;
}String ;

void initString (String *s , String *s1){
    printf("主串:");
    scanf("%s" , s->c);
    s->length = strlen(s->c);
    printf("\n子串:");
    scanf("%s" , s1->c);
    s1->length = strlen(s1->c);
}

/**
 * 创建部分匹配表
 */
void initNext(String *s1 , int *next){
    int j = 0,i;
    int k = -1;
    next[0] = -1;
    while(j < s1->length - 1){
        if(k == -1 || s1->c[k] == s1->c[j]){
            next[++j] = ++k;
        }else{
            k = next[k];
        }
    }

    printf("\n部分匹配表:");
    for(i = 0 ;i <= j ;i ++)
        printf("%d " , next[i]);
}

int KMPMatch(String *s , String *s1 , int *next){
    int ls = strlen(s->c);
    int ls1 = strlen(s1->c);
    int i = 0 , j = 0;
    while(i < ls && j < ls1){
        if(next[j] == -1 || s1->c[j] == s->c[i]){
            ++i;
            ++j;
        }else{
            j = next[j];
        }

    }

     if (j == ls1) {
        return i -2;
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
        printf("\n\n未匹配到该字符串");
    }else{
        printf("\n\n已匹配到该字符串,起始位置为%d" , num);
    }

    return 0;
}
