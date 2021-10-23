#include<iostream>
#include<string>
#include<cstring> //strlen
#include <cstdlib>
using namespace std;

#define SLEN 50

	typedef struct{   /* 建立一個自訂的struct */
		int item[SLEN];
		int top;  /* 宣告top為堆疊的頂端 */ 
	}stack; 	 /* 為stack結構 */

	stack S;
	int top = -1 ;
	
	char input[SLEN];  /* 用來存使用者輸入的式子 */
	char output[SLEN];  /* 用來存放要輸出的值 */
	
	int	operat(char ch) /* 檢查為 運算子(回傳1) or 左括號(回傳-1) or 右括號(回傳-2) or 數字(回傳0) */
	{
		if(( ch == '+')|| ( ch == '-')||( ch == '*')||( ch == '/')||( ch == '%')) 
			return 1;
		else if(ch == '(')
		 	return -1;
		else if(ch == ')')
			return -2;
		else
		 	return 0;
	} 





	int order(char ch)   /* 判斷優先順序  */
	{
		switch(ch)		 /* 將每個符號指定給一個數字， 數字越大優先權越大 */	
		{				 /* 如果*在stack裡遇到 + , *必須先出來再把+放進去 */	
			case'(':	return 0;	
			case'+':	return 1;
			case'-':	return 1;
			case'*':	return 2;
			case'/':	return 2;
			case'%':	return 2;
			default:	return -1;
		}	
	}
	
	void change(char *infix, char *output)
	{
		int i = 0 , j = 0;
		
		char val;
		
		while(( val = infix[i++] ) != '\0' )	 /* 只要還沒到最後一個數就會執行 */
		{										 /*  \0字串結束字元 */
			if(operat(val) == 0)				 /* 如果val 是數字就放到 output */
			{
				output[j++] = val;
			}
			else if(operat(val) == -1)			 /* 如果 val 是左括號就 push 到stack */
			{
				S.item[++S.top] = val;
			}
			else if(operat(val) == -2)			 /* 如果val是右括號 */
			{
				while(S.item[S.top] != '(')		 /* 只要不遇到左括號 */
				{
					output[j++] = S.item[S.top--];	 /* 將 stack 裡的數 pop 出來, 將top--(把 pop 出來的數從 stack 移除) */
				}
				S.item[S.top--];				 /* 把 '(' 從 stack 裡刪除 */
			}
			else								 /* 如果 val 是運算元 */
			{
				while(S.top > -1)				 /* 如果 stack 裡有東西 */
				{
					if(order(val) > order(S.item[S.top]))  /* 若val 的優先權大於 stack 裡的top */ 
					{
						break;					 /* 跳出此 while 迴圈 */
					} 
					else 						 /* 若 val 的優先權較小 */ 
					{
						output[j++] = S.item[S.top--]; 		/* 將 stack 裡的數 pop 出來,將top--(把 pop 出來的數從 stack 移除) */ 
					}
				} 
				
				S.item[++S.top] = val;			 /* 如果 stack 裡原本沒東西或是 val 的優先權較大 */
				 								 /* 就 push val 到 stack */
			}
		}
		while(S.top > -1 )
		{
			output[j++] = S.item[S.top--];		/* 將stack 裡的數 pop出來, 將 top--(把 pop 出來的數從 stack移除) */
		}	 
	}





int main()
{
	int a;	

	cout<<"請輸入中序運算式:"<<endl;
	
	gets(input);							 		/* 取得使用者輸入的全部字串, 包括空白字元 */
	
	change(input, output);							/* 執行中序轉後序的函式 */
	
	cout<<"該運算式的後序表示法為："<<endl;  		 
	
	int l =strlen(output);							 /* 回傳字串長度 */
	
	for(a =0 ; a <= l; a++){
		
		cout<< output[a];							 /* 將output的值一一輸出 */
	}	
	cout<<endl<<"該運算式的值為：";
	
	int x[10];
	for(int i =0 ; i<=l ; i++){
		if(output[i]!='+'){
			x[i]=output[i]-'0';
		}
		else if(output[i]!='-' ){
			x[i]=output[i]-'0';
		}
		else if(output[i]!='*' ){
			x[i]=output[i]-'0';
		}
		else if(output[i]!='/' ){
			x[i]=output[i]-'0';
		}
		else if(output[i]!='%' ){
			x[i]=output[i]-'0';
		}
			else if(output[i]!='(' ){
			x[i]=output[i]-'0';
		}
			else if(output[i]!=')' ){
			x[i]=output[i]-'0';
		}
		else if(output[i]=='+'){
			x[i-1]=x[i]+x[i-1];	
		}
		else if(output[i]=='-'){
			x[i-1]=x[i]-x[i-1];
		}
		else if(output[i]=='*'){
			x[i-1]=x[i]*x[i-1];
		}
		else if(output[i]=='/'){
			x[i-1]=x[i]/x[i-1];
		}
		else if(output[i]=='%'){
			x[i]=x[i]%x[i-1];
		}
	
	}
		cout<<x[0]+2;
			
	
	return 0;							//輸入 5 + 3 * 2 - ( 4 / 2 + 9 ) % 7 
} 
