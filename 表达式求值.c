#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAXNUM 700
#define ERROR -999
#define OK 1

struct zhan
{
    char *P_ch;
    int t;
};
typedef struct zhan *P_shizi;

struct zhan1
{
    int *P_num;
    int t;
};
typedef struct zhan1 *P_shizi1;

P_shizi create(int m)
{
    P_shizi temp;
    temp=(P_shizi)malloc(sizeof(P_shizi));
    if(temp==NULL)
    {
        printf("create temp ERROR!");
        exit(-888);
    }
    else
    {
        temp->P_ch=(char*)malloc(m*sizeof(char*));
        if(temp->P_ch==NULL)
        {
            free(temp);
            printf("create temp->P_ch ERROR!");
            exit(-888);
        }
        else
        {
            temp->t=-1;
            return temp;
        }
    }
}

P_shizi1 create1(int m)
{
    P_shizi1 temp;
    temp=(P_shizi1)malloc(sizeof(P_shizi1));
    if(temp==NULL)
    {
        printf("create1 temp ERROR!");
        exit(-888);
    }
    else
    {
        temp->P_num=(int*)malloc(m*sizeof(int*));
        if(temp->P_num==NULL)
        {
            free(temp);
            printf("create1 temp->P_ch ERROR!");
            exit(-888);
        }
        else
        {
            temp->t=-1;
            return temp;
        }
    }
}

int push(P_shizi biao,char ch)//¥Ê»Î ˝æ›
{
    if(biao->t+1>MAXNUM)
    {
        printf("push ERROR");
        return ERROR;
    }
    else
    biao->P_ch[++biao->t]=ch;
}

int put(P_shizi1 biao,int num)//¥Ê»Î ˝æ›
{
    if(biao->t+1>MAXNUM)
    {
        printf("put ERROR!");
        return ERROR;
    }
    else
    biao->P_num[++biao->t]=num;
}

int cut(P_shizi1 biao)//µØ≥ˆ ˝æ›
{
    if(biao->t>-1)
    {
        biao->t--;
        return biao->P_num[biao->t+1];
    }
    else
    {
        printf("cut ERROR!");
        return ERROR;
    }
}

void pop(P_shizi biao)//…æ≥˝ ˝æ›
{
    if(biao->t>-1)
    biao->t--;
    else
    {
        printf("pop ERROR");
    }
}

char pull(P_shizi biao)//µØ≥ˆ ˝æ›
{
    if(biao->t>-1)
    {
        biao->t--;
        return biao->P_ch[biao->t+1];
    }
}

int cla(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

void trans(char str[],char str1[],P_shizi biao)
{
    int j=0,i;
    for(i=0;str[i]!='\0';i++)
    {
        if((str[i]>='0'&&str[i]<='9')||str[i]==' ')
        str1[j++]=str[i];
        
        else if(str[i]=='(')
        {
            push(biao,str[i]);

        }
        
        else if(str[i]==')')
        {
            while(biao->P_ch[biao->t]!='(')
            str1[j++]=pull(biao);
            if(biao->P_ch[biao->t]=='(')
            pop(biao);

        }
        
        else if(str[i]!='\0')
        {
            if(str[i]=='-'&&(str[i+1]>='0'&&str[i+1]<='9'))
            {
                str1[j++]=str[i];
            }
            else if(str[i]=='-'&&i==0&&(str[i+1]<'0'||str[i+1]>'9'))
            {
                str1[j++]='0';
                push(biao,str[i]);
            }
            else if(str[i]=='+'&&i==0)
            {
                continue;
            }
            else
            {
                if(cla(str[i])>cla(biao->P_ch[biao->t]))
                push(biao,str[i]);
                else
                {
                    while(biao->t>-1&&cla(str[i])<=cla(biao->P_ch[biao->t]))
                    str1[j++]=pull(biao);
                    push(biao,str[i]);
                }
            }
        }

    }
    if(str[i]=='\0')
        while(biao->t>-1)
        str1[j++]=pull(biao);
}

void move(char str[],int len)
{
    for(int i=0;str[i]!='\0';i++)
    {
        str[i]=str[i+len];
    }
}

void poland(char str[],P_shizi1 biao)
{
    int i,a,b;

    while(str[0]!='\0')
    {
        i=0;
        if(str[0]==' ')
        while(str[i]==' ')
        i++;
        if(str[i]!=' ')
        move(str,i);
        i=0;
        
        if(str[0]>='0'&&str[0]<='9')
        {
            put(biao,atoi(str));
            i++;
            while(str[i]>='0'&&str[i]<='9')
            i++;
            if(str[i]<'0'||str[i]>'9')
            {
                while(str[i]==' ')
                i++;
                if(str[i]!=' ')
                move(str,i);
                i=0;
            }
        }
        
        else if(str[0]=='-')
        {
            if(str[1]>='0'&&str[1]<='9')
            {
                put(biao,atoi(str));
                i++;
                while(str[i]>='0'&&str[i]<='9')
                i++;
                if(str[i]<'0'||str[i]>'9')
                {
                    while(str[i]==' ')
                    i++;
                    if(str[i]!=' ')
                    move(str,i);
                    i=0;
                }
            }
            else
            {
                b=cut(biao);
                a=cut(biao);
                put(biao,a-b);
                i++;
                while(str[i]==' ')
                i++;
                if(str[i]!=' ')
                move(str,i);
                i=0;
            }
        }
        else if(str[0]=='+'||str[0]=='*'||str[0]=='/'||str[0]=='^')
        {
            b=cut(biao);
            a=cut(biao);

            if(str[0]=='+')
            put(biao,a+b);
            else if(str[0]=='*')
            put(biao,a*b);
            else if(str[0]=='/')
            put(biao,a/b);
            else if(str[0]=='^')
            put(biao,pow(a,b));
            i++;
            while(str[i]==' ')
            i++;
            if(str[i]!=' ')
            move(str,i);
            i=0;
        }
        
    }
    printf("%d",biao->P_num[biao->t]);
    return ;
}

int main()
{
    int n;
    scanf("%d\n",&n);
    
    for(int cnt=0;cnt<n;cnt++)
    {
        
        P_shizi biao;
        biao=create(MAXNUM);
        P_shizi1 biao1;
        biao1=create1(MAXNUM);
        char ch,str[1000]={'\0'},str1[1000]={'\0'};
        int k=0;
        while(~scanf("%c",&ch))
        {
            if(ch=='\n')
            break;
            else
            str[k++]=ch;
        }

        trans(str,str1,biao);
//for(int i=0;str1[i]!='\0';i++)
//printf("%c",str1[i]);
//printf("\n");
        free(biao);

        poland(str1,biao1);
        free(biao1);

        if(cnt!=n-1)
        printf("\n");
    }
}
