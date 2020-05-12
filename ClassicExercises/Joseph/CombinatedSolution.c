#include<stdio.h>
#include<stdlib.h>
#define FAIL 0
#define SUCCESS 1

typedef struct gamenode
{
    int number;
    struct gamenode* next;
 } node;

//读入初值
int getvalue(int* sum,int* count,int* alive)
{
    printf("Please input the number of People:(sum>0)\n");
    while(1)
    {
        scanf("%d",sum);
        if(*sum>0)
            break;
        printf("Invalid input, please re-enter\n");
    };
    printf("Please enter the maximum number that can be checked in:(1<=number)\n");
    while(1)
    {
        scanf("%d",count);
        if(*count>=1)
            break;
        printf("Invalid input, please re-enter\n");
    };
    printf("Please enter the number of people who need to survive last:(0<=alive<=%d)\n",*sum);
    while(1)
    {
        scanf("%d",alive);
        if(*alive >= 0 && *alive <= *sum)
            break;
        printf("Invalid input, please re-enter\n");
    };
    return SUCCESS;
}

//数组解法
//n总人数 k存活人数 s报道最大值
//时间复杂度O(n*m)
int ysfsz(int n,int k,int s)
{
    //sum此时的值为丢到海里的人数
    //j为计数器
    int i=0, *p=NULL, sum=n-k, j=1;
    //动态分配数组空间，并将首地址赋值给指针p
    if ((p = (int*)malloc(sizeof(int) * n))==NULL)
    {
    printf("FAIL!\n");
    return FAIL;
    }
    //将每个数组的值都置为1
    for(i=0;i<n;i++)
    {
        p[i]=1;
    }

    i=0;
    while(1)
    {
        //需要丢的人都进海了
        if (sum==0)
            break;
        //处理丢到海里的人，重置计数器
        if (j==s&&p[i]==1)
        {
            p[i]=0;
            j=1;
            --sum;
        }
        else if(p[i]==1)
        {   //计数器计数
            j++;
        }
        i++;
        i=i%n;
    }
    printf("\nThe position of those who survive is:");
    for(i=0;i<n;i++)
    {
        if(p[i]==1)
        printf("%d ",i+1);
    }
    printf("\n");
    printf("\nThe place to throw the sea is:");
    for(i=0;i<n;i++)
    {
        if(p[i]==0)
        printf("%d ",i+1);
    }
    printf("\n");
    free(p);
    return SUCCESS;
}

//链表解法
int ysflb(int n,int k,int s)
{
    node *h=NULL,*p=NULL,*q=NULL;
    int i=0;
    if ((h=(node*)malloc(sizeof(node)*n))==NULL)
    {
    printf("FAIL!\n");
    return FAIL;
    }
    h->number=1;
    h->next=h;
    q=h;
    for(i=1;i<n;i++)
    {
        if ((p=(node*)malloc(sizeof(node)*n))==NULL)
        {
        printf("FAIL!\n");
        exit (-1);
        }
        else
        {
            p->next=NULL;
            p->number=i+1;
            q->next=p;
            q=q->next;
        }
    }
    q->next=h;
    p=h;
    i=1;
    k=n-k;
    while(k>0)
    {
        if(i==s)
        {
            if(p!=p->next)
            {
                q->next=p->next;
                printf("%d has been thrown into the sea.\n",p->number);
                free(p);
                p=q->next;
            }
            else
            {
                printf("%d has been thrown into the sea.\n",p->number);
                p=q=h=NULL;
            }
            --k;
        }
        else
        {
            p=p->next;
            q=q->next;
        }
        ++i;
        if(i>=s+1)
        i=1;
    }
    if(p!=NULL)
    {
        printf("The rest of the survivors:");
        h=p;
        p=p->next;
        while(p!=h)
        {
            q=p->next;
            printf("%d ",p->number);
            free(p);
            p=q;
        }
        printf("%d ",h->number);
        free(h);
    }
    else
    printf("All thrown into the sea\n");
    return SUCCESS;
}

//递归解法
int ysfdg(int sum,int value,int n)
{
    if(n==1)
        return (sum+value-1)%sum;
    else
        return (ysfdg(sum-1,value,n-1)+value)%sum;
}

//主函数
int main(void)
{
    int sum=0,count=0,alive=0;

    //读入总人数，报数值，存活人数
    getvalue(&sum,&count,&alive);

    /*------------------------------------------------------------*/

    //1.约瑟夫环的数组解法
    ysfsz(sum,alive,count);

    //2.约瑟夫环的链表解法
    ysflb(sum,alive,count);

    //3. 约瑟夫环递归解法
    // int i;
    // for(i=1;i<=sum-alive;i++)
    //     printf("Number of the %2d person thrown into the sea:%2d\n",i,ysfdg(sum,count,i)+1);

    return 0;
}
