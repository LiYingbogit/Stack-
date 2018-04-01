#include <stdio.h>
#include <malloc.h>


#define STACK_INIT_SIZE 100
#define OVERFLOW -2
#define ok  1
#define ERROR 0
#define STACKINCREMENT 10
typedef int ElemType;
typedef int Status;
//ջ��˳��ṹ��ʾ
typedef struct
{
    ElemType *base;
    ElemType *top;
    int stacksize;
} SqStack;

//1.����һ����ջ
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
//2.ջ������Ԫ��
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

//3,����Ԫ��
Status StackTraverse(SqStack  S)
{
    if(S.base==NULL)
    {
        return ERROR;
    }
    if(S.top == S.base)
    {
        printf("ջ��û��Ԫ��....\n");
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

//4.ɾ��ջ��һ��Ԫ��
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

//5.��ջ��Ԫ��

Status GetTop(SqStack S,ElemType &e)
{
    if(S.top ==S.base)
        return ERROR;
    else
        e=*(S.top-1);

    return e;
}

//6.����ջ
Status DestoryStack(SqStack &S)
{
    S.top=NULL;
    S.stacksize=0;
    free(S.base);
    return ok;
}

//7.���ջ
Status ClearStack(SqStack &S)
{
    S.top=S.base;
    return ok;
}

int main()
{
    SqStack S;
    printf("����һ����ջ����\n");
    InitStack(S);
    int i ,n;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        printf("����ջ�ĵ�%d��Ԫ��\n",i);
        ++S.top;
        scanf("%d",S.top-1);
    }

    StackTraverse(S);
    printf("\n��ջ������һ��Ԫ��:");
    int e;
    scanf("%d",&e);
    Push(S,e);
    printf("\n��ջ������һ��Ԫ�غ�ջ�е�Ԫ��:");
    StackTraverse(S);
    printf("\nɾ��Ԫ�غ�ջ�е�Ԫ���ǣ�\n");
    int m;
    m=Pop(S,e);
    StackTraverse(S);
    printf("\n��ɾ����Ԫ����%d\n",m);

    int k;
    k=GetTop(S,e);
    printf("ջ��Ԫ���ǣ�%d",k);



    //printf("hello");
}
