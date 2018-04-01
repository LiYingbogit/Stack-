#include <stdio.h>
#include <malloc.h>


#define STACK_INIT_SIZE 100
#define OVERFLOW -2
#define ok  1
#define ERROR 0
#define STACKINCREMENT 10
typedef int ElemType;
typedef int Status;
//栈的顺序结构表示
typedef struct
{
    ElemType *base;
    ElemType *top;
    int stacksize;
} SqStack;

//1.构建一个空栈
Status InitStack(SqStack &S)
{
    S.base=(ElemType*)malloc(STACK_INIT_SIZE*sizeof(ElemType));
    if(!S.base)
    {
        exit(OVERFLOW);
    }
    S.top=S.base;
    S.stacksize =STACK_INIT_SIZE;
    return ok;
}
//2.栈顶插入元素
Status Push(SqStack &S,ElemType &e)
{
    if(S.top-S.base>=STACK_INIT_SIZE)
    {
        S.base =(ElemType*)realloc(S.base,(S.stacksize +STACKINCREMENT)*sizeof(ElemType));
        if(!S.base)
        {
            return false;
        }
        S.top=S.base+STACK_INIT_SIZE;
        S.stacksize = S.stacksize+STACKINCREMENT;
    }
    *S.top = e;
    S.top++;
    return ok;
}

//3,遍历元素
Status StackTraverse(SqStack  S)
{
    if(S.base==NULL)
    {
        return ERROR;
    }
    if(S.top == S.base)
    {
        printf("栈中没有元素....\n");
    }
    ElemType *p;
    p= S.top;
    while(p>S.base)
    {
        p--;
        printf("%d",*p);
    }

    return ok;
}

//4.删除栈顶一个元素
Status Pop(SqStack &S,ElemType &e)
{
    if(S.top==S.base)
        return ERROR;
    else
    {
        S.top--;
        e=*S.top;
        return e;
    }
}

//5.求栈顶元素

Status GetTop(SqStack S,ElemType &e)
{
    if(S.top ==S.base)
        return ERROR;
    else
        e=*(S.top-1);

    return e;
}

//6.销毁栈
Status DestoryStack(SqStack &S)
{
    S.top=NULL;
    S.stacksize=0;
    free(S.base);
    return ok;
}

//7.清空栈
Status ClearStack(SqStack &S)
{
    S.top=S.base;
    return ok;
}

int main()
{
    SqStack S;
    printf("构造一个空栈……\n");
    InitStack(S);
    int i ,n;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        printf("输入栈的第%d个元素\n",i);
        ++S.top;
        scanf("%d",S.top-1);
    }

    StackTraverse(S);
    printf("\n向栈顶插入一个元素:");
    int e;
    scanf("%d",&e);
    Push(S,e);
    printf("\n向栈顶插入一个元素后栈中的元素:");
    StackTraverse(S);
    printf("\n删除元素后栈中的元素是：\n");
    int m;
    m=Pop(S,e);
    StackTraverse(S);
    printf("\n被删除的元素是%d\n",m);

    int k;
    k=GetTop(S,e);
    printf("栈顶元素是：%d",k);



    //printf("hello");
}
