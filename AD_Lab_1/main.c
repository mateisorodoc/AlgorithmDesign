#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct nod {
    int key;
    struct nod *next;
} TIP_NOD;

TIP_NOD *q, *first = NULL, *last = NULL;

void insert(int k) {

    TIP_NOD *p, *q1;
    int opt;
    int givenKey;

    p = (TIP_NOD *) malloc(sizeof(TIP_NOD));

    p->key = k; //give the node the key inserted by the user

    if (q == NULL) { //intrare in lista vida
        p->next = NULL;
        last = p;
        first = p;
        q = p;
    }

    else{
        printf("Lista nu este vida");

        printf("\nChoose where to insert new node:\n");
        printf("\n1. Before first node.\n2. After last node.\n3. After desired node k1.\n4. Before desired node k1\n0. EXIT\n");
        scanf("%d", &opt); //NOLINT
        switch (opt) {
            case 1:
                p->next = first;
                first = p;
                printf("Node inserted before the first node");
                break;
            case 2:
                p->next = NULL;
                last->next = p;
                last = p;
                printf("Node inserted after the last node");
                break;
            case 3:
                printf("Please insert the key of the node that you want to insert before: ");
                scanf("%d", &givenKey); //NOLINT
                q1 = NULL;
                q = first;
                while (q != NULL) { //searching for the node with the key givenKey
                    if (q->key == givenKey) break;
                    q1 = q;
                    q = q->next;
                }

                if (q != NULL) {
                    //node with key givenKey has address q
                    if (q == first) {
                        //insert after first node
                        p->next = first;
                        first = p;
                    }

                    else {
                        q1->next = p;
                        p->next = q;
                    }
                }
                break;
            case 4:
                printf("Please insert the key of the node that you want to insert after: ");
                scanf("%d", &givenKey); //NOLINT
                q1 = NULL;
                q = first;
                while (q != NULL) { //searching for the node with the key givenKey
                    if (q->key == givenKey) break;
                    q = q->next;
                }

                if (q != NULL) {
                    p->next = q->next; /* node with key givenKey has address q */
                    q->next = p;
                    if (q == last)
                        last = p;
                }
                break;
            case 0:
                break;
            default:
                printf("\n ERROR!");
        }
    }
}


void display() {

    TIP_NOD *tmp = first;

    if (q == NULL) {
        printf("The list is empty!");
    }

    else {
        while (tmp != NULL) {
            printf("Key = %d\n", tmp->key);
            tmp = tmp->next;
        }
    }
}

void delete(int givenKey) {
    TIP_NOD *q1;
    q1 = NULL;
    q = first;
    while (q != NULL) { //searching for the node with the key givenKey
        if (q->key == givenKey) break;
        q1 = q;
        q = q->next;
    }

    if (q != NULL) {
        if (q == first) {
            first = first->next;
            free(q);
            if (first == NULL)
                last = NULL;
        }

        else {
            q1->next = q->next;
            if (q == last) last = q1;
            free(q);
        }
    }
}

void saveListInFile() {

    FILE *fout = fopen("fileOUT.txt", "w");
    TIP_NOD *tmp;

    if (q == NULL)
        fprintf(fout, "The list is empty!");

    else
    {
        tmp = first;
        while (tmp != NULL) {
            fprintf(fout, "%d ", tmp->key);
            tmp = tmp->next;
        }
    }
    fclose(fout);
}

void  readListFromFile(){

    FILE *fin = fopen("fileIN.txt", "r");
    if(fin == NULL){
        exit(1);
    }

    int val;
    while(fscanf(fin, "%d", &val)>0){ //NOLINT

        TIP_NOD *p = (TIP_NOD *) malloc(sizeof(TIP_NOD));

        if (q == NULL) { //intrare in lista vida
            p->next = NULL;
            last = p;
            first = p;
            q = p;
        }

        else {
            p->key = val;
            p->next = NULL;
            last->next = p;
            last = p;
        }

    }


    fclose(fin);
}

int main() {

    int key = 0;

    int optOp = -1;

    while (optOp != 0) {

        printf("\nChoose what operation you want to make: \n");
        printf("\n1. Read from file\n2. Insert node\n3. Display\n4. Save in file\n5. Delete\n0. EXIT\n");
        printf("\nOption: \n");

        scanf("%d", &optOp); //NOLINT

        switch (optOp) {
            case 1:
                printf("\nReading from file fileIN.txt...\n");
                readListFromFile();
                break;
            case 2:
                printf("\nInsert the key for the node you want to create:\n");
                scanf("%d", &key); //NOLINT
                insert(key);
                break;
            case 3:
                display();
                break;
            case 4:
                saveListInFile();
                printf("\nThe list has been saved to fileOUT.txt\n");
                break;
            case 5:
                printf("\nInsert the key for the node you want to DELETE:\n");
                scanf("%d", &key); //NOLINT
                delete(key);
                break;
            case 0:
                return 0;
            default:
                printf("\nERROR!\n");
        }
    }
    return 0;
}
