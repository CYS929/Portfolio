#include<iostream>
#include<stdlib.h>
#include<cstring>
using namespace std;

#define MAX_ELEMENTS 200
int heap[MAX_ELEMENTS];
int num;
void printHeap(){
	int i;
	if(num == 0)
		cout<<"Heap�O�Ū�"<<endl;
	for(i = 1 ; i <= num; i++)
		cout<<"���"<<i<<"��"<<heap[i]<<endl; 
}
void insert(int val){
	int i;
	
	if(num >= MAX_ELEMENTS)
		cout<<"Heap���F"<<endl;
	
	i = ++num; //����ڬ�Heap[1]

// �T�w�𦳭ȡA�n�[�J���Ƥj�󥦪�PARENT
	while( (i != 1) && (val > heap[i/2]) )
	{
		heap[i] = heap [i/2];
		i /= 2 ; //PARENT�W���� 
	 }
// �T�w�𦳭ȡA�n�[�J���Ƥj�󥦪�PARENT

	heap[i] = val; //�𬰪ũέn�[�J���Ƥp�󥦪�PARENT�A������JHEAP�� 
}

void deleteMax(){
	int parent , child , temp ;
	
	if(num == 0){
		cout<<"Heap�O�Ū�"<<endl;
		return;
	}
	
	temp = heap[num--];
	
	parent = 1;
	child = 2;
	cout<<"�R��"<<heap[parent] <<endl;
	
	while(child <= num){
		//���O�̫�@�Ӽ� �B���l��<�k�l��
		if((child<num) && (heap[child]) < heap[child+1])
		child++;  //��ܥk�l�� 
		//���O�̫�@�Ӽ� �B���l��>�k�l��
		
		//�p�G�̫�@�ӼƸ��j�A���XWHILE�j�� 
		if(temp >= heap[child])
			break;
			
		heap[parent] = heap [child];  //child�ȩ��PARENT������l 
		parent = child;   //�쥻��CHILD�ܦ� PARENT 
		child *= 2;  //�s��CHILD���U�� 
	}
	//�̫�@�ӼƬ��ƪ��̤j�ȡA������J���
	heap[parent] = temp; 
}

int main(){
	int input,val;
	int num = 0;
	do{
		system("cls"); //�M�ŵe��
		
		cout<<endl;
		cout<<"(1) �s�W�@�ӭ�<insert>"<<endl;
		cout<<"(2) �R���̤j��<deleteMax>"<<endl;
		cout<<"(3) �C�L��Ӱ�n<printHeap>"<<endl;
		cout<<"(4) ���}�{��<Exit>"<<endl;
		cout<<"��J�n���檺�ﶵ:";
		cin >> input;
		cout<< endl;
		
		switch (input) {
			case 1:
				cout<<"��J0�H�פ�"<<endl;
				
				do{
					cout<<"��J�s�W����:";
					cin >> val;
					
					if(val!=0)
						insert(val); 
				}while(val != 0);
				system("PAUSE");
				break;
			
			case 2:
				deleteMax();
				cout<<endl;
				system("PAUSE");
				break;
			
			case 3:
				printHeap();
				cout<<endl;
				system("PAUSE");
				break;
				
			case 4:
				system("PAUSE");
				break;
			
			default:
				cout<<"�п�J1��4���Ʀr"<<endl; 
		}
	}while(input != 4);
 	return 0;
} 
