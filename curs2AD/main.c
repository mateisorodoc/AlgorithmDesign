#include <stdio.h>
#include <stdlib.h>
typedef struct nod{
    int key;
    struct nod *next;
} TIP_NOD;

TIP_NOD *q, *first, *last, *r;

int main() {
    first = NULL;
    last = NULL;
    return 0;
}

void create(int k){
    TIP_NOD *p, *q1;
    q = (TIP_NOD*)malloc(sizeof (TIP_NOD ));
    p->key = k;

    if(q == NULL){ //intrare in lista vida
        p->next = NULL;
        last = p;
        first = p;
        q = p;
    }
    else{
        printf("Lista nu este vida");
        //cases

        //before first
        p->next = first;
        first = p;

        //after last
        p->next = NULL;
        last->next = p;
        last = p;

        //after desired node k1
        q1 = search(k1);
        p->next = q1->next;
        q1->next = p;

        //before desired node q1
        //r = previous node, k = cheia de cautat
        q = first;
        r = first;
        while(q != NULL){
            if(q->key == k) break;
            else{
                r = q;
                q = q->next;
            }
        }
        if(q == NULL) {
            printf("k not found");
            free(p);
        }
        else{
            p->next = q;
            r->next = p;
            if(q == first){
                first = p;
            }
        }

    }


}