#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

struct Stack{
    int top;
    unsigned capacity;
    char *a;
};

struct Stack* createStack(unsigned capacity){
    struct Stack* exstack = (struct Stack*)malloc(sizeof(struct Stack));
    exstack->capacity = capacity;
    exstack-> top = -1;
    exstack->a = (char*)malloc(exstack->capacity * sizeof(char));
    return exstack;
}
bool isempty(struct Stack* exstack){
    if(exstack-> top == -1)
    return true;
    else return false;
}
bool isfull(struct Stack* exstack){
    if(exstack-> top == exstack->capacity -1)
    return true;
    else return false;
}

void push(struct Stack* exstack, char element){
    if(isfull(exstack))
        printf("Stack Overflow");
    else
        exstack->a[++exstack->top] = element;
}

void pop(struct Stack* exstack){
    if(isempty(exstack))
        printf("Stack Underflow");
    else
    exstack->top--; 

}


bool checkParenthesis(char a, char b){
    if(a=='(' && b==')' || a=='{' && b=='}' || a=='[' && b==']') return true;
    return false;
}


void reverse(char *str, int length){
    struct Stack *s =createStack(length);
    char arr[length];
    int j=length-1;
    for(int i=0;i<length;i++){
        arr[j] = str[i];
        j--;
    }
    printf("The reversed String is: %s",arr);
}

int main(){

printf("Enter expression:");
char *str = NULL;
size_t size = 0;
getline(&str,&size,stdin);
str[strlen(str) - 1] = '\0';

reverse(str,(int)strlen(str));
return 0;
}

