#include <stdio.h>
#include <stdlib.h>
//#include <curses.h>
#include <ctype.h>
#include <string.h>

//global variables declaration

typedef struct nod{
    int key;
    struct nod *next;
} TIP_NOD;

TIP_NOD *q, *first = NULL, *last = NULL, *r;

void create(int k){
    TIP_NOD *p, *q1;
    int opt;
    int givenKey;

    p = (TIP_NOD*)malloc(sizeof (TIP_NOD ));

    p->key = k; //give the node the key inserted by the user

    if(q == NULL){ //intrare in lista vida
        p->next = NULL;
        last = p;
        first = p;
        q = p;
    }
    else{
        printf("Lista nu este vida");

        printf("\nChoose where to insert new node:\n");
        printf("\n1. Before first node.\n2. After last node.\n3. After desired node k1.\n4. Before desired node k1\n0. EXIT\n");
        scanf("%d", &opt);
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
                scanf("%d", &givenKey);
                q1 = NULL;
                q = first;
                while ( q != NULL ) { //searching for the node with the key givenKey
                    if ( q->key == givenKey ) break;
                    q1 = q;
                    q = q->next;
                }

                if( q != NULL){
                    //node with key givenKey has address q
                    if(q == first){
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
                scanf("%d", &givenKey);
                q1 = NULL;
                q = first;
                while ( q != NULL ) { //searching for the node with the key givenKey
                    if ( q->key == givenKey ) break;
                    q1 = q;
                    q = q->next;
                }

                if ( q != NULL ) {
                    p->next = q->next; /* node with key givenKey has address q */
                    q->next = p;
                    if ( q == last )
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


void display(){
TIP_NOD *tmp = first;

if(q == NULL){
    printf("The list is empty!");
}

else{
    while(tmp != NULL){
        printf("Key = %d\n", tmp->key);
        tmp = tmp->next;
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

    if ( q != NULL ) {
        if(q == first){
            first = first->next;
            free(q);
            if(first == NULL)
                last = NULL;
        }
        else{
            q1->next = q->next;
            if(q == last) last = q1;
            free(q);
        }
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


//function declaration
//void read(){
//    int i, j;
//    FILE *fin = fopen("fileIN.txt", "r");
//    for(i = 0; i < n; i++)
//        for(j = 0; j < n; j++)
//            fscanf(fin, "%d", &a[i][j]);
//
//    fclose(fin);
//}

//void save(){
//    int i, j;
//    FILE *fout = fopen("fileOUT.txt", "w");
//    for(i = 0; i < n; i++)
//        for(j = 0; j < n; j++){
//            fprintf(fout, "\t%d ", a[i][j]);
//            printf("%d ", a[i][j]);
//        }
//    fprintf(fout, "\nProdusul este: %d", p);
//    printf("\nProdus = %d", p);
//    fclose(fout);
//}

//int validateName(char x[]){
//    int i, k;
//    for(i = 0; i < strlen(x); i++)
//    {
//        if(isdigit(x[i]) == 1){
//            printf("ERROR");
//            k = 0;
//        }
//        else
//            k = 1;
//    }
//
//    if(k == 0)
//        return 0;
//    else
//        return 1;
//
//}
//
//void readName(){
//    char x[10];
//    int i = 0;
//    while (1) {
//        printf("Enter a name: ");
//        scanf("%s", x);
//        if (strcmp(x, "0") == 0) {
//            printf("Finished");
//            break;
//        }
//
//        if (validateName(x) == 0)
//            printf("Nume eronat");
//        else {
//            v[i] = (STUDENT *) malloc(sizeof(STUDENT));
//            strcpy(v[i]->nume, x);
//            v[i]->nr = i;
//            i++;
//        }
//    }
//    n = i - 1;
//}



//void compute(){
//    int i, j;
//    for (i = 0; i < n; ++i)
//        for (j = 0; j < n; j++)
//            if(i == j)
//                p = p * a[i][j];
//}

int main() {
int key = 0;

    int optOp= -1;

    while (optOp != 0){
        printf("\nChoose what operation you want to make: \n");
        printf("1. Create\n2. Display\n3. Save\n4. Delete\n0. EXIT");
        printf("\nOption: ");
        scanf("%d", &optOp);

        switch (optOp) {
            case 1:
                printf("Insert the key for the node you want to create:\n");
                scanf("%d", &key);
                create(key);
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
