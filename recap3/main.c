#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char name[20];
    struct node *next;
    struct node *prev;
} NODE;

NODE *q, *first = NULL, *last = NULL;

void create(char name[]){

    NODE *p = (NODE *) malloc(sizeof (NODE));

    strcpy(p->name, name);

    if(first == NULL){
        last = p;
        first = p;
        p->next = NULL;
        p->prev = NULL;
    }

    else printf("\nLista nu este vida\n");

}

void insert(char name[20]){

    NODE *p = (NODE *) malloc((sizeof (NODE)));
    char findName[20];
    int opt = -1;

    if(first == NULL){
        printf("\nLista este vida!\n");
    }

    else{

        strcpy(p->name, name);

        printf("\nUnde doriti sa inserati?\n");
        printf("\n1. Before first\n2. After last\n3. Before node k\n4. After node k\n0. Exit\n");
        scanf("%d", &opt); //NOLINT

        switch (opt) {
            case 1:
                p->next = first;
                p->prev = NULL;
                first->prev = p;
                first = p;
                break;
            case 2:
                p->next = NULL;
                p->prev = last;
                last->next = p;
                last = p;
                break;
            case 3:
                printf("\nThe key of the node you want to search for: \n");
                scanf("%s", findName);

                q = first;

                while (q != NULL){
                    if(strcmp(q->name, findName) == 0) break;
                    q = q->next;
                }

                if(q != NULL){
                    if(q == first){
                        p->next = first;
                        p->prev = NULL;
                        first->prev = p;
                        first = p;
                    }
                    else{
                        q->prev->next = p;
                        p->prev = q->prev;
                        q->prev = p;
                        p->next = q;
                    }
                }
                break;
            case 4:
                printf("\nThe key of the node you want to search for: \n");
                scanf("%s", findName);

                q = first;

                while (q != NULL){
                    if(strcmp(q->name, findName) == 0) break;
                    q = q->next;
                }

                if(q != NULL){
                    if(q == last){
                        p->next = NULL;
                        p->prev = last;
                        last->next = p;
                        last = p;
                    }

                    else{
                        q->next->prev = p;
                        p->next = q->next;
                        q->next = p;
                        p->prev = q;

                    }

                }
                break;
            case 0:
                break;
            default:
                printf("ERROR");
                break;

        }

    }

}

void display(){

    for(q = first; q != NULL; q = q->next){
        printf("%s\n", q->name);
    }

}

void delete(char name[20]){

    q = first;

    while (q != NULL){
        if(strcmp(q->name, name) == 0) break;
        q = q->next;
    }

    if(q != NULL){
        if(q == first){
            first = first->next;
            first->prev = NULL;
            free(q);
        }
        else if(q == last){
            last = last->prev;
            last->next = NULL;
        }
        else if(first == q && last == q){
            first = NULL;
            last = NULL;
            free(q);
        }
        else{
            q->prev->next = q->next;
            q->next->prev = q->prev;
        }
    }

}



int main() {
    int optOp = -1;
    char name[20];

    while (optOp != 0) {
        printf("\nChoose what operation you want to make: \n");
        printf("1. Create\n2. Insert\n3. Display\n4. Delete\n0. EXIT\n");
        printf("\nOption: ");
        scanf("%d", &optOp); //NOLINT

        switch (optOp) {
            case 1:
                printf("Insert the key for the node you want to create:\n");
                scanf("%s", name); //NOLINT
                create(name);
                break;
            case 2:
                printf("Insert the key for the node you want to insert:\n");
                scanf("%s", name); //NOLINT
                insert(name);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Insert the key for the node you want to DELETE:\n");
                scanf("%s", name); //NOLINT
                delete(name);
                break;
            case 0:
                return 0;
            default:
                printf("\n ERROR!");
        }
    }
    return 0;
}
