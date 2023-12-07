#include <stdio.h>
#define MAX 4

int stack_arr[MAX];
int top = -1;
void push(int data);
int pop();
int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    int data = pop();
    printf("%d",data);
    pop();
    pop();
    pop();
    pop();

    return 0;
}
void push(int data){
    if(top == MAX - 1){
        printf("Stack overflow");
        return;
    }
    top++;
    stack_arr[top] = data;
}
int pop(){
    if(top == -1){
        printf("Stack underflow");
        return;
    }
    int value;
    value = stack_arr[top];
    top--;
    return value;
}