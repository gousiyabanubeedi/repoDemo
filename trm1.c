#include<stdio.h>
#include<ctype.h>
#define SIZE 50
struct stack{
    char stack[SIZE]; 
    int top;
};
void push (struct stack*s ,char x){
    s->top++;
    s->stack[s->top]=x;
}
char pop (struct stack*s){
     char x;
     x= s->stack[s->top];
     s->top--;
     return x;
}
int pri(char sym){
    if(sym == '^')
    return 6;
    else if(sym=='*'|| sym=='/')
    return 3;
    else if(sym =='+'|| sym=='-')
    return 1;
    else
    return 0;
}

int prs(char sym){
    if(sym == '^')
    return 5;
    else if(sym=='*'|| sym=='/')
    return 4;
    else if(sym =='+'|| sym=='-')
    return 2;
    else
    return 0;
}
int main(){
    struct stack s;
    s.top=-1;
    char infix[SIZE],postfix[SIZE],ch,element;
    int i=0,j=0;
    printf("enter valid infix expresion :");
    scanf("%s" , infix);
    while((ch=infix[i])!='\0'){
if(ch=='(')
push(&s,ch);
else if(isalnum(ch))
postfix[j++]=ch;
else if(ch==')')
  {  
while(s.stack[s.top]!='(')
    postfix[j++]=pop(&s);
    element=pop(&s);
  }
  else{
while(pri(ch)<=prs(s.stack[s.top]))
    postfix[j++]=pop(&s);
      push(&s,ch);
  }
  i++;
  }
while(s.top!=-1)
     postfix[j++]=pop(&s);
     postfix[j++]='\0';
printf(" the required infix expression :%s ",postfix);

} 


