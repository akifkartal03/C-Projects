#include<stdio.h>
#include<stdlib.h>

void gamePlay();
void createPuzzle(char *words[]);


int main(){
    gamePlay();
    return 0;
}

void gamePlay(){
    char *words[6];
    int size = 4;
    createPuzzle(words);
    for (int i = 0; i < 6; i++)
    {
        printf("%s", words[i]);
    }
    //continue making game from here
}

void createPuzzle(char *words[]){
    FILE *fptr;
    fptr =fopen("puzzle.txt","r");
    if(fptr==NULL){
        printf("File open error!!\n");
        return;
    }
    char **ppc;
    ppc = words;
    int i=0;
    size_t len = 0;
    size_t read;
    ppc = words + i;
    //words[i] = NULL;
    *ppc= NULL;
    while ((read = getline(&(*ppc), &len, fptr)) != -1) {
        //printf("Retrieved line of length %zu:\n", read);
        //printf("%s", *ppc);
        i++;
        ppc = words + i;
        *ppc = NULL;
    }
    fclose(fptr);
}