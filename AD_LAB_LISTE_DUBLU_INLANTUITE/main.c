#include <stdio.h>
#include <stdlib.h>
//#include <curses.h>
#include <ctype.h>
#include <string.h>

//global variables declaration

typedef struct nod{
    int key;
    struct nod *next;
    struct nod *prev;
} TIP_NOD;

TIP_NOD *q, *first = NULL, *last = NULL, *r;

void insert(int k){
    TIP_NOD *p, *q1;
    int opt;
    int givenKey;

    p = (TIP_NOD*)malloc(sizeof (TIP_NOD ));

    p->key = k; //give the node the key inserted by the user

    if(q == NULL){ //intrare in lista vida
        p->next = NULL;
        p->prev = NULL;
        last = p;
        first = p;
        q = p;
    }
    else{
        printf("Lista nu este vida");

        printf("\nChoose where to insert new node:\n");
        printf("\n1. Before first node.\n2. After last node.\n3. Before desired node k1.\n4. After desired node k1\n0. EXIT\n");
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                p->next = first;
                p->prev = NULL;
                first->prev = p;
                first = p;
                printf("Node inserted before the first node");
                break;
            case 2:
                p->next = NULL;
                p->prev = last;
                last->next = p;
                last = p;
                printf("Node inserted after the last node");
                break;
            case 3:
                printf("Please insert the key of the node that you want to insert before: ");
                scanf("%d", &givenKey);
                q = first;
                while ( q != NULL ) { //searching for the node with the key givenKey
                    if ( q->key == givenKey ) break;
                    q = q->next;
                }

                if( q != NULL){
                    //node with key givenKey has address q
                    if(q == first){
                        //insert before first node
                        p->next = first;
                        p->prev = NULL;
                        first->prev = p;
                        first = p;
                    }
                    else {
                        q->prev->next = p;
                        p->prev = q->prev;
                        q->prev = p;
                        p->next = q;
                    }
                }
                break;
            case 4:
                printf("Please insert the key of the node that you want to insert after: ");
                scanf("%d", &givenKey);
                q = first;
                while ( q != NULL ) { //searching for the node with the key givenKey
                    if ( q->key == givenKey ) break;
                    q = q->next;
                }

                if ( q != NULL ) {

                    p->next = q->next;

                    if(q->next == NULL)
                        last = p;

                    else
                        q->next->prev = p;
                    q->next = p;
                    p->prev = q;


                }
                break;

            case 0:
                break;

            default:
                printf("\n ERROR!");
        }
    }

}



void display(){
    TIP_NOD *tmp = first;
    int opt = -1;

    if(q == NULL){
        printf("The list is empty!");
    }

    else {
        while (opt != 0) {
            printf("\nOption:\n1. Forwards\n2.Backwards\n0. Return\n");
            scanf("%d", &opt);

            switch (opt) {
                case 1:
                    for (tmp = first; tmp != NULL; tmp = tmp->next)
                        printf("%d ", tmp->key);
                    break;
                case 2:
                    for(tmp = last; tmp != NULL; tmp = tmp->prev)
                        printf("%d ", tmp->key);
                    break;
            }

        }
    }
}

void delete(int givenKey){
    TIP_NOD *p, *q1;
    q1 = NULL;
    q = first;
    while ( q != NULL ) { //searching for the node with the key givenKey
        if ( q->key == givenKey ) break;
        q1 = q;
        q = q->next;
    }
    if(first == q && last == q ){
        first = NULL;
        last = NULL;
        free(q);
    }
    else if(q == first){
        first = first->next;
        first->prev = NULL;
        free(q);
    }
    else if(q == last){
        last = last->prev;
        last->next = NULL;
        free(q);
    }
    else{
        q->next->prev = q->prev;
        q->prev->next = q->next;
    }
}

void saveListInFile(){
    FILE *fout = fopen("fileOUT.txt", "w");
    TIP_NOD *tmp;

    if(q == NULL){
        fprintf(fout, "The list is empty!");
    }

    else{
        tmp = first;
        while(tmp != NULL){
            fprintf(fout, "%d ", tmp->key);
            tmp = tmp->next;
        }
    }
    fclose(fout);
}


int main() {
    int key = 0;

    int optOp= -1;

    while (optOp != 0){
        printf("\nChoose what operation you want to make: \n");
        printf("1. Insert\n2. Display\n3. Save\n4. Delete\n0. EXIT");
        printf("\nOption: ");
        scanf("%d", &optOp);

        switch (optOp) {
            case 1:
                printf("Insert the key for the node you want to create:\n");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                display();
                break;
            case 3:
                saveListInFile();
                printf("The list has been saved to fileOUT.txt");
                break;
            case 4:
                printf("Insert the key for the node you want to DELETE:\n");
                scanf("%d", &key);
                delete(key);
                break;
            case 0:
                return 0;
            default:
                printf("\n ERROR!");
        }
    }
    return 0;
}
