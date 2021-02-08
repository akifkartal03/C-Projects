#include "logic.h"

void createCircuit(){
    int andG = 0, orG = 0, notG = 0, flipG = 0 , inG = 0;
    int isAnd = 0, isOR = 0, isNot = 0, isFlip = 0, isIn = 0;
    int andI = 0, orI = 0, notI = 0, flipI = 0, inI = 0,i = 0;
    getNumberOfComponents(&andG,&orG,&notG,&flipG,&inG);
    int total = inG+andG+orG+notG+flipG ;
    circuit *circ;
    circ = (circuit*)malloc(sizeof(circuit));
    circ->ins=(input*)malloc(sizeof(input)*total);
    circ->ands=(and_gate*)malloc(sizeof(and_gate)*andG);
    circ->ors=(or_gate*)malloc(sizeof(or_gate)*orG);
    circ->nots=(not_gate*)malloc(sizeof(not_gate)*notG);
    circ->flips=(flipflop*)malloc(sizeof(flipflop)*flipG);
    FILE *fptr = fopen("circuit.txt","r");
    if(fptr==NULL){
        printf("File open error!!\n");
        return;
    }
    char * line = NULL;
    size_t len = 0;
    size_t read;
    char *pch = NULL;
    int k = 0;
    while ((read = getline(&line, &len, fptr)) != -1) {
        pch = strtok (line," \n");
        if (strcmp(pch,"AND") == 0)
            isAnd = 1;
        else if(strcmp(pch,"OR") == 0)
            isOR = 1 ;
        else if(strcmp(pch,"NOT") == 0)
            isNot = 1;
        else if(strcmp(pch,"FLIPFLOP") == 0)
            isFlip = 1;
        else if(strcmp(pch,"INPUT") == 0){
            int j = 0;
            while (pch != NULL)
            {
                pch = strtok (NULL, " \n");
                if(pch != NULL){
                    strcpy(circ->ins[j].id,pch);
                    circ->ins[j].data = 0;
                    j++;
                }

            }
            inI=j;
        }
        i = 0;
        while (pch != NULL)
        {
            pch = strtok (NULL, " \n");
            if(pch != NULL){
                if (isAnd == 1){
                    if (i == 0)
                    {
                        strcpy(circ->ands[andI].id,pch);
                    }
                    else if (i == 1)
                    {
                        circ->ands[andI].in1 = getInput(pch,circ->ins,total);
                    }
                    else if (i == 2)
                    {
                        circ->ands[andI].in2 = getInput(pch,circ->ins,total);
                        circ->ands[andI].out = 0;
                        circ->ands[andI].index = k;
                    }
                }
                else if(isOR == 1){
                    if (i == 0)
                    {
                        strcpy(circ->ors[orI].id,pch);
                    }
                    else if (i == 1)
                    {
                        circ->ors[orI].in1 = getInput(pch,circ->ins,total);
                    }
                    else if (i == 2)
                    {
                        circ->ors[orI].in2 = getInput(pch,circ->ins,total);
                        circ->ors[orI].out = 0;
                        circ->ors[orI].index = k;

                    }
                }
                else if(isNot == 1){
                    if (i == 0)
                    {
                        strcpy(circ->nots[notI].id,pch);
                    }
                    else if (i == 1)
                    {
                        circ->nots[notI].in1 = getInput(pch,circ->ins,total);
                        circ->nots[notI].out = 0;
                        circ->nots[notI].index = k;
                    }
                }
                else if(isFlip == 1){
                    if (i == 0)
                    {
                        strcpy(circ->flips[flipI].id,pch);
                    }
                    else if (i == 1)
                    {
                        circ->flips[flipI].in1 = getInput(pch,circ->ins,total);
                        circ->flips[flipI].out = 0;
                        circ->flips[flipI].former = 0;
                        circ->flips[flipI].index = k;
                    }
                }
                i++;
            }
            else{
                if (isAnd == 1){
                    isAnd = 0;
                    strcpy(circ->ins[inI].id,circ->ands[andI].id);
                    circ->ins[inI].data = circ->ands[andI].out;
                    andI++;
                    inI++;

                }
                else if(isOR == 1){
                    isOR = 0;
                    strcpy(circ->ins[inI].id,circ->ors[orI].id);
                    circ->ins[inI].data = circ->ors[orI].out;
                    orI++;
                    inI++;
                }
                else if(isNot == 1){
                    isNot = 0;
                    strcpy(circ->ins[inI].id,circ->nots[notI].id);
                    circ->ins[inI].data = circ->nots[notI].out;
                    notI++;
                    inI++;
                }
                else if(isFlip == 1){
                    isFlip = 0;
                    strcpy(circ->ins[inI].id,circ->flips[flipI].id);
                    circ->ins[inI].data = circ->flips[flipI].out;
                    flipI++;
                    inI++;
                }
            }
        }
        k++;
    }

    fclose(fptr);
    resolveCircuit(circ,andG,orG,notG,flipG,inG);
    /*
    printf("-----------INPUTS----------\n");
    for (int i = 0; i < total; i++)
	{
        printf("name: %s----data: %d\n",circ->ins[i].id,circ->ins[i].data);
	}
    circ->ins[0].data = 1;
    circ->ins[1].data = 1;
    printf("-----------INPUTS----------\n");
    for (int i = 0; i < total; i++)
	{
        printf("name: %s----data: %d\n",circ->ins[i].id,circ->ins[i].data);
	}
    printf("-----------ANDS------------\n");
    for (int i = 0; i < andG; i++)
	{
        printf("name: %s\n",circ->ands[i].id);
        printf("name1: %s----data1: %d\n",circ->ands[i].in1.id,circ->ands[i].in1.data);
        printf("name2: %s----data2: %d\n",circ->ands[i].in2.id,circ->ands[i].in2.data);
        printf("out: %d\n",circ->ands[i].out);
        printf("index: %d\n",circ->ands[i].index);
        printf("-----------------------------\n");
	}

    printf("-----------ORS--------------\n");
    for (int i = 0; i < orG; i++)
	{
        printf("name: %s\n",circ->ors[i].id);
        printf("name1: %s----data1: %d\n",circ->ors[i].in1.id,circ->ors[i].in1.data);
        printf("name2: %s----data2: %d\n",circ->ors[i].in2.id,circ->ors[i].in2.data);
        printf("out: %d\n",circ->ors[i].out);
        printf("-----------------------------\n");
	}
    printf("-----------NOTS--------------\n");
    for (int i = 0; i < notG; i++)
	{
        printf("name: %s\n",circ->nots[i].id);
        printf("name1: %s----data1: %d\n",circ->nots[i].in1.id,circ->nots[i].in1.data);
        printf("out: %d\n",circ->nots[i].out);
        printf("-----------------------------\n");
	}
    printf("-----------FLIPS--------------\n");
    for (int i = 0; i < notG; i++)
	{
        printf("name: %s\n",circ->flips[i].id);
        printf("name1: %s----data1: %d\n",circ->flips[i].in1.id,circ->flips[i].in1.data);
        printf("out: %d\n",circ->flips[i].out);
        printf("-----------------------------\n");
	}*/

}
void resolveCircuit(circuit *circ,int andG,int orG,int notG,int flipG,int ins){
    FILE *fptr2 = fopen("output.txt","w");
    if(fptr2 == NULL)
    {
        printf("File open error!!\n");
        return;
    }
    FILE *fptr = fopen("input.txt","r");
    if(fptr==NULL){
        printf("File open error!!\n");
        return;
    }
    char * line = NULL;
    size_t len = 0;
    size_t read;
    char *pch = NULL;
    int i = 0,isFound=0;
    int size = andG+orG+notG+flipG;
    int total = andG+orG+notG+flipG+ins;
    while ((read = getline(&line, &len, fptr)) != -1) {
        pch = strtok (line," \n");
        i = 0;
        while (pch != NULL)
        {
            circ->ins[i].data = atoi(pch);
            i++;
            pch = strtok (NULL, " \n");
        }
        for (int k = 1; k <= size; k++)
        {
            isFound = 0;
            for (int j = 0; (j < andG) && (isFound == 0); j++)
            {
                if(circ->ands[j].index == k){
                    isFound = 1;
                    circ->ands[j].in1 = getInput(circ->ands[j].in1.id,circ->ins,total);
                    circ->ands[j].in2 = getInput(circ->ands[j].in2.id,circ->ins,total);
                    if (circ->ands[j].in1.data == 1 && circ->ands[j].in2.data == 1)
                    {
                        circ->ands[j].out = 1;
                        setInput(circ->ins,1,circ->ands[j].id,total);

                    }
                    else{
                        circ->ands[j].out = 0;
                        setInput(circ->ins,0,circ->ands[j].id,total);
                    }
                    if (k == size)
                    {
                        circ->out = circ->ands[j].out;
                    }


                }
            }
            for (int j = 0; (j < orG) && (isFound == 0); j++)
            {
                if(circ->ors[j].index == k){
                    isFound = 1;
                    circ->ors[j].in1 = getInput(circ->ors[j].in1.id,circ->ins,total);
                    circ->ors[j].in2 = getInput(circ->ors[j].in2.id,circ->ins,total);
                    if (circ->ors[j].in1.data == 0 && circ->ors[j].in2.data == 0)
                    {
                        circ->ors[j].out = 0;
                        setInput(circ->ins,0,circ->ors[j].id,total);

                    }
                    else{
                        circ->ors[j].out = 1;
                        setInput(circ->ins,1,circ->ors[j].id,total);
                    }
                    if (k == size)
                    {
                        circ->out = circ->ors[j].out;
                    }
                }
            }
            for (int j = 0; (j < notG) && (isFound == 0); j++)
            {
                if(circ->nots[j].index == k){
                    isFound = 1;
                    circ->nots[j].in1 = getInput(circ->nots[j].in1.id,circ->ins,total);
                    if (circ->nots[j].in1.data == 0)
                    {
                        circ->nots[j].out = 1;
                        setInput(circ->ins,1,circ->nots[j].id,total);

                    }
                    else{
                        circ->nots[j].out = 0;
                        setInput(circ->ins,0,circ->nots[j].id,total);
                    }
                    if (k == size)
                    {
                        circ->out = circ->nots[j].out;
                    }
                }
            }
            for (int j = 0; (j < flipG) && (isFound == 0); j++)
            {
                if(circ->flips[j].index == k){
                    isFound = 1;
                    circ->flips[j].in1 = getInput(circ->flips[j].in1.id,circ->ins,total);
                    if (circ->flips[j].in1.data == circ->flips[j].former )
                    {
                        circ->flips[j].out = 0;
                        circ->flips[j].former = 0;
                        setInput(circ->ins,0,circ->flips[j].id,total);

                    }
                    else{
                        circ->flips[j].out = 1;
                        circ->flips[j].former = 1;
                        setInput(circ->ins,1,circ->flips[j].id,total);
                    }
                    if (k == size)
                    {
                        circ->out = circ->flips[j].out;
                    }

                }
            }
        }
        fprintf(fptr2,"%d\n",circ->out);
    }
    fclose(fptr2);
    fclose(fptr);

}

void getNumberOfComponents(int *andG,int *orG,int *notG,int *flipG, int *ins){
    FILE *fptr = fopen("circuit.txt","r");
    if(fptr==NULL){
        printf("File open error!!\n");
        return;
    }
    char * line = NULL;
    size_t len = 0;
    size_t read;
    char *pch = NULL;
    while ((read = getline(&line, &len, fptr)) != -1) {
        pch = strtok (line," \n");
        if (strcmp(pch,"AND") == 0)
            *andG = *andG + 1;
        else if(strcmp(pch,"OR") == 0)
            *orG = *orG + 1;
        else if(strcmp(pch,"NOT") == 0)
            *notG = *notG + 1;
        else if(strcmp(pch,"FLIPFLOP") == 0)
            *flipG = *flipG + 1;
        else if(strcmp(pch,"INPUT") == 0){

            while (pch != NULL)
            {
                pch = strtok (NULL, " \n");
                if(pch != NULL){
                    *ins = *ins + 1;
                }
            }

        }
    }
    fclose(fptr);
}

input getInput(char name[10],input *ins,int size){
    for (int i = 0; i < size; i++)
	{
		if(strcmp(ins[i].id,name) == 0){
            return ins[i];
        }
	}
    return ins[0];
}
void setInput(input *ins,int data,char name[10],int size){
    for (int i = 0; i < size; i++)
	{
		if(strcmp(ins[i].id,name) == 0){
            ins[i].data = data;
        }
	}
}