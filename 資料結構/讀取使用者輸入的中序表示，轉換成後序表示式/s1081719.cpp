#include<iostream>
#include<string>
#include<cstring> //strlen
#include <cstdlib>
using namespace std;

#define SLEN 50

	typedef struct{   /* �إߤ@�Ӧۭq��struct */
		int item[SLEN];
		int top;  /* �ŧitop�����|������ */ 
	}stack; 	 /* ��stack���c */

	stack S;
	int top = -1 ;
	
	char input[SLEN];  /* �ΨӦs�ϥΪ̿�J�����l */
	char output[SLEN];  /* �ΨӦs��n��X���� */
	
	int	operat(char ch) /* �ˬd�� �B��l(�^��1) or ���A��(�^��-1) or �k�A��(�^��-2) or �Ʀr(�^��0) */
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





	int order(char ch)   /* �P�_�u������  */
	{
		switch(ch)		 /* �N�C�ӲŸ����w���@�ӼƦr�A �Ʀr�V�j�u���v�V�j */	
		{				 /* �p�G*�bstack�̹J�� + , *�������X�ӦA��+��i�h */	
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
		
		while(( val = infix[i++] ) != '\0' )	 /* �u�n�٨S��̫�@�ӼƴN�|���� */
		{										 /*  \0�r�굲���r�� */
			if(operat(val) == 0)				 /* �p�Gval �O�Ʀr�N��� output */
			{
				output[j++] = val;
			}
			else if(operat(val) == -1)			 /* �p�G val �O���A���N push ��stack */
			{
				S.item[++S.top] = val;
			}
			else if(operat(val) == -2)			 /* �p�Gval�O�k�A�� */
			{
				while(S.item[S.top] != '(')		 /* �u�n���J�쥪�A�� */
				{
					output[j++] = S.item[S.top--];	 /* �N stack �̪��� pop �X��, �Ntop--(�� pop �X�Ӫ��Ʊq stack ����) */
				}
				S.item[S.top--];				 /* �� '(' �q stack �̧R�� */
			}
			else								 /* �p�G val �O�B�⤸ */
			{
				while(S.top > -1)				 /* �p�G stack �̦��F�� */
				{
					if(order(val) > order(S.item[S.top]))  /* �Yval ���u���v�j�� stack �̪�top */ 
					{
						break;					 /* ���X�� while �j�� */
					} 
					else 						 /* �Y val ���u���v���p */ 
					{
						output[j++] = S.item[S.top--]; 		/* �N stack �̪��� pop �X��,�Ntop--(�� pop �X�Ӫ��Ʊq stack ����) */ 
					}
				} 
				
				S.item[++S.top] = val;			 /* �p�G stack �̭쥻�S�F��άO val ���u���v���j */
				 								 /* �N push val �� stack */
			}
		}
		while(S.top > -1 )
		{
			output[j++] = S.item[S.top--];		/* �Nstack �̪��� pop�X��, �N top--(�� pop �X�Ӫ��Ʊq stack����) */
		}	 
	}





int main()
{
	int a;	

	cout<<"�п�J���ǹB�⦡:"<<endl;
	
	gets(input);							 		/* ���o�ϥΪ̿�J�������r��, �]�A�ťզr�� */
	
	change(input, output);							/* ���椤�����Ǫ��禡 */
	
	cout<<"�ӹB�⦡����Ǫ�ܪk���G"<<endl;  		 
	
	int l =strlen(output);							 /* �^�Ǧr����� */
	
	for(a =0 ; a <= l; a++){
		
		cout<< output[a];							 /* �Noutput���Ȥ@�@��X */
	}	
	cout<<endl<<"�ӹB�⦡���Ȭ��G";
	
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
			
	
	return 0;							//��J 5 + 3 * 2 - ( 4 / 2 + 9 ) % 7 
} 
