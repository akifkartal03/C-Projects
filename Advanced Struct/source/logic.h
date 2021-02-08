#ifndef LOGIC
#define LOGIC

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct logic1
{
    char id[10];
    int data;
}input;

typedef struct logic2
{
    char id[10];
    input in1;
    input in2;
    int out;
    int index;

}and_gate;

typedef struct logic3
{
    char id[10];
    input in1;
    input in2;
    int out;
    int index;
}or_gate;

typedef struct logic4
{
    char id[10];
    input in1;
    int out;
    int index;
}not_gate;

typedef struct logic5
{
    char id[10];
    input in1;
    int former;
    int out;
    int index;
}flipflop;

typedef struct logic6
{
   input *ins;
   and_gate *ands;
   or_gate *ors;
   not_gate *nots;
   flipflop *flips;
   int out;

}circuit;

void createCircuit();
void resolveCircuit(circuit *circ,int andG,int orG,int notG,int flipG,int ins);
void getNumberOfComponents(int *andG,int *orG,int *notG,int *flipG,int *ins);
input getInput(char name[10],input *ins,int size);
void setInput(input *ins,int data,char name[10],int size);


#endif
