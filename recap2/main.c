#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char name[20];
    struct node *next;
} NODE;

NODE *q, *first = NULL, *last = NULL;

void read_from_file(){

    FILE *fin = fopen("fileIN.txt", "r");
    char readName[20];

    if(fin == NULL){
        printf("ERROR AT READING FROM FILE");
    }

    while(fscanf(fin, "%s", readName)>0){

        NODE *p = (NODE *) malloc(sizeof (NODE));

        strcpy(p->name, readName);

        if(first == NULL){
            first = p;
            last = p;
            p->next = NULL;
        }

        else{
            last->next = p;
            last = p;
            p->next = NULL;
        }

    }

    fclose(fin);

}

void insert_after_last(char name[20]) {

    NODE *p = (NODE *) malloc(sizeof (NODE));

    strcpy(p->name, name);

    if(first != NULL){
        last->next = p;
        last = p;
        p->next = NULL;
    }

    else printf("The list is empty!");

}

void display(){

    q = first;

    while(q != NULL){
        printf("%s\n", q->name);
        q = q->next;
    }

}

void delete(char name[20]){

    NODE *prevNode = NULL;
    q = first;

    while(q != NULL){
        if(strcmp(q->name, name) == 0) break;
        prevNode = q;
        q = q->next;
    }

    if(q != NULL) {
        if (q == first) {
            first = first->next;
            free(q);
            if(first == NULL){
                last = NULL;
            }
        }
        else{
            prevNode->next = q->next;
            if(q == last){
                prevNode = last;
            }
            free(q);
        }
    }

}

int main() {

    int opt = -1;
    char name[20];

    while(opt != 0){

        printf("Option:\n");
        printf("\n1. Read list from file.\n2. Insert new node in list\n3. Display list\n4. Delete\n0. EXIT\n");

        scanf("%d", &opt); //NOLINT

        switch (opt) {
            case 1:
                read_from_file();
                break;
            case 2:
                printf("\nInsert then name of the node:\n");
                scanf("%s", name);
                insert_after_last(name);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nInsert then name of the node ypu want to delete:\n");
                scanf("%s", name);
                delete(name);
            case 0:
                break;
            default:
                break;
        }

    }
    return 0;
}
