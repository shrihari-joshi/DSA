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
char top(struct Stack* exstack){
    return exstack->a[exstack->top];
}


bool checkParenthesis(char a, char b){
    if(a=='(' && b==')' || a=='{' && b=='}' || a=='[' && b==']') return true;
    return false;
}

void match(char *str,int length){
    struct Stack* s = createStack(length);
    int i,c=0;
    for(i=0;str[i]!='\0';i++){
        if(str[i] == '(' || str[i] == '{' || str[i] == '[')
        push(s,str[i]);
        if(str[i] == ')' || str[i] == '}' || str[i] == ']')
            {
                if(!isempty(s) && checkParenthesis(top(s),str[i]))
                {pop(s);}
                else{
                    c=1;
                    break;
                }
            }
    }
    
    if(isempty(s) && c==0)
    {printf("Parenthesis Matched");}
    else
    {printf("Parenthesis didn't Match at %d",i+1);}
}

int main(){

printf("Enter expression:");
char *str = NULL;
size_t size = 0;
getline(&str,&size,stdin);
str[strlen(str) - 1] = '\0';
match(str,(int)strlen(str));
return 0;
}

