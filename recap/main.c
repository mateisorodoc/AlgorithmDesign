#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node{
    char name[20];
    struct node *next;
} NODE;

NODE *first, *last, *q;

void create(char name[]){

    first = NULL;
    last = NULL;

    NODE *p = (NODE *)malloc(sizeof (NODE));

    strcpy(p->name, name);

    p->next = NULL;

    //intrare in lista vida
    if(last != NULL)
        last->next = p;
    else
        first = p;
    last = p;
}


void insert(char name[20]){

    NODE *p = (NODE *)malloc(sizeof (NODE));
    NODE *prevNode;
    int opt = -1;

    if(first==NULL)
        printf("\nThe list is empty! Try to create one first!\n");

    else {

            strcpy(p->name, name);

            printf("Choose option:\n");
            printf("\n1. Before first node\n2. After last node\n3. Before node with name n\n4. After node with name n\n");

            scanf("%d", &opt);

            switch (opt) {
                case 1:
                    p->next = first;
                    first = p;
                    printf("\nInserted before first node\n");
                    break;
                case 2:
                    p->next = NULL;
                    last->next = p;
                    last = p;
                    printf("\nInserted after last node\n");
                    break;
                case 3:
                    printf("\nPlease insert the name of the node you want to search for:\n");
                    scanf("%s", name);
                    prevNode = NULL;
                    q = first;

                    //search function
                    while (q != NULL) {
                        if (strcmp(q->name, name) == 0) break;
                        prevNode = q;
                        q = q->next;
                    }

                    if (q != NULL) {

                        //check if the node q is first
                        if (q == first) {

                            //insert before first node
                            p->next = NULL;
                            first = p;
                        } else {
                            prevNode->next = p;
                            p->next = q;
                        }
                    }
                    break;

                case 4:
                    printf("\nPlease insert the name of the node you want to search for:\n");
                    scanf("%s", name);
                    q = first;

                    //search function
                    while (q != NULL) {
                        if (strcmp(q->name, name) == 0) break;
                        prevNode = q;
                        q = q->next;
                    }

                    if (q != NULL) {

                        //check if inserting after last node
                        if (q == last) {
                            q->next = p;
                            p->next = NULL;
                            last = p;
                        } else {
                            p->next = q->next;
                            q->next = p;

                        }
                    }
                    break;

                case 0:
                    break;
                default:
                    printf("ERROR AT INSERTING");
                    break;
            }
        }
}

void delete(char name[]){

    NODE *q1,  *p;

    q1 = NULL;
    q = first;

    while (q != NULL){
        if(strcmp(q->name, name) == 0) break;
        q1 = q;
        q = q->next;
    }

    if(q != NULL){
        if(q == first){
            first = first->next;
            free(q);
            if(first == NULL)
                last = NULL;
        }
        else{
            q1->next = q->next;

            if(q == last)
                q1 = last;
            free(q);
        }
    }
}

void display(){

    q = first;

    if(q == NULL)
        printf("THE LIST IS EMPTY");

    while (q != NULL){
        printf("\nKEY: %s\n", q->name);
        q = q->next;
    }
}

 void read_from_file(){

    char readName[20];

    FILE *fin = fopen("fileIN.txt", "r");

    while(fscanf(fin, "%s", readName)>0){

        NODE *p = (NODE *) malloc(sizeof (NODE));

        strcpy(p->name, readName);

        if(fin == NULL){
            exit(1);
        }
        else {
            if (last != NULL)
                last->next = p;
            else
                first = p;
            last = p;
        }
    }

     fclose(fin);

}

void save_in_file(){

    FILE *fout = fopen("fileOUT.txt", "w");

    q = first;

    while (q != NULL){
        fprintf(fout, "%s ", q->name);
        q = q->next;
    }

    fclose(fout);

}

int main() {

    read_from_file();
    display();
    delete("are");
    insert("pere");
    save_in_file();
    display();
    return 0;
}

