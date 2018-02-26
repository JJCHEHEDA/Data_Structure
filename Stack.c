#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct Node{
    int data;
    struct Node *next;
}node;//node 等价与struct Node *

typedef struct Stack{
    node *top; //头节点
    node *button; //尾节点
};

//初始化一个栈
void initStack(struct Stack *stack)
{
    //创建一个空节点，让top指向它
    stack->top = (struct Node *)malloc(sizeof(struct Node));
    if (stack->top == NULL){
        printf("malloc error!\n");
        return ;
    }
    stack->button = stack->top;
    //清空 空节点的指针域
    stack->top->next = NULL;
}

//元素入栈,从栈顶插入
void pushStack(struct Stack *stack, int e)
{
    //动态创建一个新节点
    struct Node *now = (struct Node*)malloc(sizeof(struct Node));
    now->data = e;
    now->next = stack->top;
    stack->top = now;
}

//打印栈中的元素
void printfStack(struct Stack *stack)
{
    //新建一个节点，以它来遍历
    struct Node *now = stack->top;
    while(stack->button != now){
        printf("the one of stack is %d\n", now->data);
        now = now->next;
    }
}

//取出栈顶元素，并删除栈顶
int popStack(struct Stack *stack, int * val)
{
    if (isEmpty(stack)) return 0;
    else{
        struct Node *now = stack->top;
        *val = now->data;
        stack->top = now->next;
        free(now);
        now = NULL;
        return 1;
    }
}

//判断栈是否为空
int isEmpty(struct Stack *stack)
{
    if (stack->top == stack->button) return 1;
    else return 0;
}

//清空栈
void clearStack(struct Stack *stack)
{
    if (isEmpty(stack)) return ;
    else {
        struct Node *p = stack->top;
        struct Node *q = NULL;
        while(p != stack->button){
            q = p->next;
            free(p);
            p = q;
        }
        stack->top = stack->button;
    }
}


int main(int argc, char *argv[])
{
    int num;
    struct Stack stack_one;

    initStack(&stack_one);
    //printfStack(&stack_one);
    printf("现在输入六个数据进栈\n");
    for (int i=0 ; i<6 ; i++)
    {
        scanf("%d", &num);
        pushStack(&stack_one, num);
    }
    printfStack(&stack_one);
    if (popStack(&stack_one, &num)) printf("出栈的元素是%d\n", num);
    else printf("出栈失败!'n");
    clearStack(&stack_one);
    printfStack(&stack_one);
    return 0;
}


//参考自http://www.jb51.net/article/94445.htm 
