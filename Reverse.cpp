//将单向链表reverse，如ABCD变成DCBA，只能搜索链表一次
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using  namespace std;

typedef struct  Node
{
	char str;
	Node *next;
}Node;

void CreateLinkList(Node *head)
{
	Node *node = NULL;
	Node *pre = head;
	char c;
	cout<<"please input the number of data."<<endl;
	int num = 0;
	cin>>num;
	for(int i = 0;i < num;i++)
	{
		node = (Node*)malloc(sizeof(Node));
		cout<<"input the "<<i<<" data:"<<endl;
		cin>>c;
		node->str = c;
		node->next = NULL;
		pre->next = node;
		pre = node;
	}
}
void Change(Node *head)
{
	Node *p = head->next;
	//这俩情况没有意义
	if(p == NULL || p->next ==NULL)
		return ;
	Node *next = p->next;
	while(next != NULL)
	{
		p->next = next->next;
		next->next = head->next;
		head->next = next;
		next = p->next;

	}
}
void Display(Node *head)
{
	Node *p = head;
	if(p->next == NULL)
		return;
	p = p->next;
	while(p != NULL)
	{
		cout<<"-->"<<p->str;
		p = p->next;
	}
	cout<<endl;
}
void main(){  

	Node *head = (Node *)malloc(sizeof(Node));
	head->next = NULL;
	CreateLinkList(head);
	Display(head);
	Change(head);
	Display(head);
	system("pause");  
}  