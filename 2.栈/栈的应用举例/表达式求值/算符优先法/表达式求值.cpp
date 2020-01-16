#include <stdio.h>
#include <stdlib.h>

#define maxsize 20

typedef struct
{
    char data[maxsize];
    int top;
} sqstack;
//< 1
//>2
//=3
int match[7][7]={{2,2,1,1,1,2,2},
				 {2,2,1,1,1,2,2},
				 {2,2,2,2,1,2,2},
				 {2,2,2,2,1,2,2},
				 {1,1,1,1,1,3,0},
				 {2,2,2,2,0,2,2},
				 {1,1,1,1,1,0,3},
};
void init_sqstack(sqstack &s);//��ʼ��ջ
void push(sqstack &s, char x);//��ջ
char pop(sqstack &s);//��ջ
char gettop(sqstack s);//ȡ��ջ��Ԫ��
bool isoprator(char c);//�Ƿ�Ϊ������
int preceed(char a,char b)
{
	int x;
	switch(a)
	{
		case '+':
				switch(b)
				{
					case '+':
						x=match[0][0];
						break;
					case '-':
						x=match[0][1];
						break;
					case '*':
						x=match[0][2];
						break;
					case '/':
						x=match[0][3];
						break;
					case '(':
						x=match[0][4];
						break;
					case ')':
						x=match[0][5];
						break;
					case '#':
						x=match[0][6];
						break;
				}
			break;
		case '-':
			switch(b)
				{
					case '+':
						x=match[1][0];
						break;
					case '-':
						x=match[1][1];
						break;
					case '*':
						x=match[1][2];
						break;
					case '/':
						x=match[1][3];
						break;
					case '(':
						x=match[1][4];
						break;
					case ')':
						x=match[1][5];
						break;
					case '#':
						x=match[1][6];
						break;
				}
			break;
		case '*':
			switch(b)
				{
					case '+':
						x=match[2][0];
						break;
					case '-':
						x=match[2][1];
						break;
					case '*':
						x=match[2][2];
						break;
					case '/':
						x=match[2][3];
						break;
					case '(':
						x=match[2][4];
						break;
					case ')':
						x=match[2][5];
						break;
					case '#':
						x=match[2][6];
						break;
				}
			break;
		case '/':
			switch(b)
				{
					case '+':
						x=match[3][0];
						break;
					case '-':
						x=match[3][1];
						break;
					case '*':
						x=match[3][2];
						break;
					case '/':
						x=match[3][3];
						break;
					case '(':
						x=match[3][4];
						break;
					case ')':
						x=match[3][5];
						break;
					case '#':
						x=match[3][6];
						break;
				}
			break;
		case '(':
			switch(b)
				{
					case '+':
						x=match[4][0];
						break;
					case '-':
						x=match[4][1];
						break;
					case '*':
						x=match[4][2];
						break;
					case '/':
						x=match[4][3];
						break;
					case '(':
						x=match[4][4];
						break;
					case ')':
						x=match[4][5];
						break;
					case '#':
						x=match[4][6];
						break;
				}
			break;
		case ')':
			switch(b)
				{
					case '+':
						x=match[5][0];
						break;
					case '-':
						x=match[5][1];
						break;
					case '*':
						x=match[5][2];
						break;
					case '/':
						x=match[5][3];
						break;
					case '(':
						x=match[5][4];
						break;
					case ')':
						x=match[5][5];
						break;
					case '#':
						x=match[5][6];
						break;
				}
			break;
		case '#':
			switch(b)
				{
					case '+':
						x=match[6][0];
						break;
					case '-':
						x=match[6][1];
						break;
					case '*':
						x=match[6][2];
						break;
					case '/':
						x=match[6][3];
						break;
					case '(':
						x=match[6][4];
						break;
					case ')':
						x=match[6][5];
						break;
					case '#':
						x=match[6][6];
						break;
				}
			break;
			}
	return x;

}
int oprate(char a1,char op,char b1)
{
    int a=int(a1)-48;
    int b=int(b1)-48;
	int x;
	switch(op)
	{
		case '+':
			x=a+b;
			break;
		case '-':
			x=a-b;
			break;
		case '*':
			x=a*b;
			break;
		case '/':
			x=a/b;
			break;
	}
	return x;
}
int evaluateexpression()
{
    char c;
    int x;
    sqstack num;//��Ų�����
    sqstack ch;//��Ų�����
    init_sqstack(num);
    init_sqstack(ch);
    push(ch,'#');
    c=getchar();
    char num1;
    char luo;
    char num2;
	while(c!='#')
	{
		if(!isoprator(c))//it is not oprator
		{
			push(num,c);
            c=getchar();
		}
		else
		{//< 1
		//>2
		//=3
			switch(preceed(gettop(ch),c))
			{

				case 1:
					push(ch,c);
                    c=getchar();
					break;
				case 2:
                    luo=pop(ch);
                    num1=pop(num);
                    num2=pop(num);
                    push(num,char(oprate(num1,luo,num2)+48));
					break;
				case 3:
                    pop(ch);
                    c=getchar();
					break;
			}
		}
	}
    luo=pop(ch);
    num1=pop(num);
    num2=pop(num);
    push(num,char(oprate(num1,luo,num2)+48));
    x=int(gettop(num))-48;
    return x;
}

int main()
{
    int x;
    //x=evaluateexpression();
    x=oprate('6','/','3');
	printf("%d",x);
    system("pause");
    return 0;
}
bool isoprator(char c)
{
    if(c=='+' || c=='*' || c=='-' || c=='/' || c=='(' || c==')')
    {
        return true;
    }
    else
    {
        return false;
    }

}
void init_sqstack(sqstack &s)
{
    s.top = -1;
}
void push(sqstack &s, char x)
{
    s.top++;
    s.data[s.top] = x;
}
char pop(sqstack &s)
{
    char x;
    x = s.data[s.top];
    s.top--;
    return x;
}
char gettop(sqstack s)
{
    char x;
    x = s.data[s.top];
    return x;
}