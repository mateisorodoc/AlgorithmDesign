#include <stdio.h>
#include <stdlib.h>

typedef struct nod{
    int key;
    struct nod *next, *prev;
} TIP_NOD;

//before first
p->next = first;
p->prev = 0;
first->prev = p;
first = p;

//after last
p->next = 0;
p->prev = last;
last->next = p;
last = p;

//before key k1
p->next = q;
p->prev = q->prev;
q->prev->next = p;
q->prev = p;

//after key k1
p->next = q->next;
p->prev = q;
q->next = p;
if(q == last){
    last = p;
}
else
    q->next->prev = p;

//delete k1
q->prev->next = q->next;
q->next->prev = q->prev;
free(q);

int main(){
    return 0;
}