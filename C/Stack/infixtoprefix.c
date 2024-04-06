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
    exstack->a[exstack->top--];

}
char top(struct Stack* exstack){
    return exstack->a[exstack->top];
}

bool isOperator(char c){
    if(c =='+' || c =='-' || c =='*' || c =='/' ) return true;
    else return false;
    }   

bool isOperand(char c){
    if(c>='a' && c<='z') return true;
    if(c>='A' && c<='Z') return true;
    if(c>='1' && c<='9') return true;
    return false;
    }

int precedence(char c){
    switch(c)
    {
    case '+' :
    case '-' :
    return 1;
    case '*' :
    case '/' :
    return 2;
    }
}

bool checkParenthesis(char a, char b){
    if(a=='(' && b==')') return true;
    if(a=='{' && b=='}') return true;
    if(a=='[' && b==']') return true;
    return false;
}

void Convert(char *str,int length,char *output){
    struct Stack* exstack = createStack(length);
    int i=0,j=0;

    while(str[i] != '\0')
    {
    i++;
    }

    while(i>=0)
    {
    if(isOperand(str[i]))
        {
            output[j] = str[i];
            j++;
            i--;
        }
    else if(isOperator(str[i]))
        {
            while(!isempty(exstack) && isOperator(top(exstack)) && (precedence(str[i]) < precedence(top(exstack))))
            {
            output[j] = top(exstack); 
            pop(exstack);
            j++;
            }
            push(exstack,str[i]);
            i--;
        }
    else if(str[i]==')' || str[i]=='}' || str[i]==']')
        {
            push(exstack,str[i]);
            i--;
        }
    else if(str[i]=='(' || str[i]=='{' || str[i]=='[')
        {
            while(checkParenthesis(str[i], top(exstack)) == false)
            {
                output[j] = top(exstack);
                pop(exstack);
                j++;
            }
        pop(exstack);
        i--;
        }
        else
        i--;
    }
    while(!isempty(exstack))
    {
        output[j] = top(exstack);
        pop(exstack);
        j++;
    }
    output[j] = '\0';
}

int main(){

printf("Enter infix expression : ");
char *str = NULL;
size_t size = 0;
getline(&str,&size,stdin);


char output[(int)strlen(str)];
Convert(str,(int)strlen(str),output);
printf("The prefix expression is : ");
int i=(int)strlen(output) - 1;

while(i>=0)
{
printf("%c",output[i]);
i--;
}

return 0;
}

