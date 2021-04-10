#include<iostream>
#include<stdlib.h>

using namespace std;

struct node
{
	int data;
	struct node* next;
};

int main()
{
	struct node* head, * p, * q, * t;
	int i, n, a;
	cin >> n;
	//链表初始化
	head = NULL;
	q = NULL;
	//创建链表
	for (i = 1;i <= n;i++)
	{
		cin >> a;
		p = (struct node*)malloc(sizeof(struct node));
		p->data = a;
		p->next = NULL;
		if (head == NULL)
		{
			head = p;
			q = p;
		}
		else
		{
			q->next = p;
			q = p;
		}

		
	}
	cin >> a;
	//遍历链表
	t = head;
	while (t != NULL)
	{
		if (t->next->data > a)
		{
			//链表的插入
			p = (struct node*)malloc(sizeof(struct node));
			p->data = a;
			p->next = t->next;
			t->next = p;
			break;
		}
		t = t->next;
	}
	//遍历链表
	t = head;
	while (t != NULL)
	{
		cout << t->data << " ";
		t = t->next;
	}
	system("pause");
	return 0;
}
