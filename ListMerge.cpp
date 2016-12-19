#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct List{
    int num;
    List *next;
}List;

void print(List *list){
    List *t = list;
    while(t != NULL){
        cout <<t->num << " ";
        t = t->next;
    }
    cout <<""<<endl;
}

List *MergeList(List *list , List *list2){
    if(list == NULL)
        return list2;
    else if(list2 == NULL)
        return list;

    List *temp = NULL;
    if(list->num < list2->num){
        temp = list;
        temp->next = MergeList(list->next , list2);
    }else{
        temp = list2;
        temp->next = MergeList(list , list2->next);
    }

    return temp;
}

int main(){
    List *l1 = new List;
    l1->next = NULL;
    l1->num = 0;
    List *l2 = new List;
    l2->next = NULL;
    l2->num = 1;
    for(int i = 10 ;i >= 2 ;i -= 2){
        List *t = new List;
        t->next = l1->next;
        l1->next = t;
        t->num = i;
    }

    for(int i = 11 ;i >= 3 ;i -= 2){
        List *t = new List;
        t->next = l2->next;
        l2->next = t;
        t->num = i;
    }

    print(l1);
    print(l2);

    cout << "ÅÅÐòºó" <<endl;
    print(MergeList(l1 ,l2));

    return 0;
}
