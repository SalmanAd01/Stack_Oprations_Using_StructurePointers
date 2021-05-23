#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};
int isempty(struct stack *ptr)  //To check if stack is empty
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull(struct stack *ptr) //To check if stack is empty
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *ptr, int value) //To add the elements in Stack
{
    if (isfull(ptr))
    {
        printf("Elements can't be push in stack\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}
int pop(struct stack *ptr) //To remove the element (First Element) from the Stack
{
    int oldvalue;
    if (isempty(ptr))
    {
        printf("Stack Underflow, You can't pop the element from the stack\n");
        return -1;
    }
    else
    {
        oldvalue = ptr->arr[ptr->top];
        ptr->top--;
        return oldvalue;
    }
}
int peak(struct stack *ptr, int location) //To find the Value at Particular Postion in the stack
{
    int index;
    index = ptr->top - location + 1;
    if (index < 0)
    {
        printf("Invalid Position\n");
    }
    else
    {
        return ptr->arr[index];
    }
}
int topelement(struct stack *ptr) //To Get the Top Element Of The Stack
{
    if (isempty(ptr))
    {
        printf("Stack is empty can't see his top element\n");
        return -1;
    }
    else
    {
        return ptr->arr[ptr->top];
    }
}
int bottomelement(struct stack *ptr)//To Get the Top Element Of The Stack
{
    if (isempty(ptr))
    {
        printf("Stack is empty can't see his top element\n");
    }
    else
    {
        return ptr->arr[0];
    }
}
int main()
{
    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    int checkiffull;
    int checkifempty;
    printf("Stack is created\n");
    checkiffull = isfull(s);
    checkifempty = isempty(s);
    if (checkiffull == 1)
    {
        printf("Stack Overflow\n");
    }
    if (checkifempty == 1)
    {
        printf("Stack Underflow\n");
    }
    printf("Pushing element in the stack\n");
    push(s, 57);
    push(s, 10);
    push(s, 90);
    push(s, 100);
    printf("Poping elements in the stack\n");
    printf("%d\n", pop(s));
    printf("%d\n", pop(s));
    printf("Value at position 2 is %d\n", peak(s, 2));
    printf("Value at position 1 is %d\n", peak(s, 1));
    printf("Top most elements in the stack is %d\n",topelement(s));
    printf("Bottom most elements in the stack is %d\n",bottomelement(s));
    return 0;
}