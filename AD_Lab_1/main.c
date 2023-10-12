#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

//global variables declaration
int a[2][2], n = 2, p = 1;

//function declaration
void read(){
    int i, j;
    FILE *fin = fopen("fileIN.txt", "r");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            fscanf(fin, "%d", &a[i][j]);

    fclose(fin);
}

void save(){
    int i, j;
    FILE *fout = fopen("fileOUT.txt", "w");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++){
            fprintf(fout, "\t%d ", a[i][j]);
            printf("%d ", a[i][j]);
        }
    fprintf(fout, "\nProdusul este: %d", p);
    printf("\nProdus = %d", p);
    fclose(fout);
}

void compute(){
    int i, j;
    for (i = 0; i < n; ++i)
        for (j = 0; j < n; j++)
            if(i == j)
                p = p * a[i][j];
}

int main() {

    int opt = -1;
    while (opt != 0){
        printf("\nEnter data...\n");
        printf("\nOption: ");
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                read();
                break;
            case 2:
                compute();
                break;
            case 3:
                save();
                break;
            case 0:
                return 0;
            default:
                printf("\n ERROR!");
        }
    }
    return 0;
}
