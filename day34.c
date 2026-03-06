/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

void push(Node** top,int x){
    Node* n=malloc(sizeof(Node));
    n->data=x;
    n->next=*top;
    *top=n;
}

int pop(Node** top){
    Node* t=*top;
    int x=t->data;
    *top=t->next;
    free(t);
    return x;
}

int main(){
    char s[1000];
    fgets(s,1000,stdin);
    Node* top=NULL;
    char* t=strtok(s," \n");
    while(t){
        if(isdigit(t[0]) || (t[0]=='-' && isdigit(t[1]))){
            push(&top,atoi(t));
        }else{
            int b=pop(&top);
            int a=pop(&top);
            int r;
            if(t[0]=='+') r=a+b;
            else if(t[0]=='-') r=a-b;
            else if(t[0]=='*') r=a*b;
            else r=a/b;
            push(&top,r);
        }
        t=strtok(NULL," \n");
    }
    printf("%d",pop(&top));
    return 0;
}
