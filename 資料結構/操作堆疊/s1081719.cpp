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
		cout<<"Heap是空的"<<endl;
	for(i = 1 ; i <= num; i++)
		cout<<"欄位"<<i<<"為"<<heap[i]<<endl; 
}
void insert(int val){
	int i;
	
	if(num >= MAX_ELEMENTS)
		cout<<"Heap滿了"<<endl;
	
	i = ++num; //讓樹根為Heap[1]

// 確定樹有值，要加入的數大於它的PARENT
	while( (i != 1) && (val > heap[i/2]) )
	{
		heap[i] = heap [i/2];
		i /= 2 ; //PARENT上移動 
	 }
// 確定樹有值，要加入的數大於它的PARENT

	heap[i] = val; //樹為空或要加入的數小於它的PARENT，直接放入HEAP中 
}

void deleteMax(){
	int parent , child , temp ;
	
	if(num == 0){
		cout<<"Heap是空的"<<endl;
		return;
	}
	
	temp = heap[num--];
	
	parent = 1;
	child = 2;
	cout<<"刪除"<<heap[parent] <<endl;
	
	while(child <= num){
		//不是最後一個數 且左子樹<右子樹
		if((child<num) && (heap[child]) < heap[child+1])
		child++;  //選擇右子樹 
		//不是最後一個數 且左子樹>右子樹
		
		//如果最後一個數較大，跳出WHILE迴圈 
		if(temp >= heap[child])
			break;
			
		heap[parent] = heap [child];  //child值放到PARENT指的位子 
		parent = child;   //原本的CHILD變成 PARENT 
		child *= 2;  //新的CHILD往下移 
	}
	//最後一個數為數的最大值，直接放入樹根
	heap[parent] = temp; 
}

int main(){
	int input,val;
	int num = 0;
	do{
		system("cls"); //清空畫面
		
		cout<<endl;
		cout<<"(1) 新增一個值<insert>"<<endl;
		cout<<"(2) 刪除最大值<deleteMax>"<<endl;
		cout<<"(3) 列印整個堆積<printHeap>"<<endl;
		cout<<"(4) 離開程式<Exit>"<<endl;
		cout<<"輸入要執行的選項:";
		cin >> input;
		cout<< endl;
		
		switch (input) {
			case 1:
				cout<<"輸入0以終止"<<endl;
				
				do{
					cout<<"輸入新增的值:";
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
				cout<<"請輸入1～4的數字"<<endl; 
		}
	}while(input != 4);
 	return 0;
} 
