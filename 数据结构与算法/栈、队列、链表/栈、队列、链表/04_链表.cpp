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
	//�����ʼ��
	head = NULL;
	q = NULL;
	//��������
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
	//��������
	t = head;
	while (t != NULL)
	{
		if (t->next->data > a)
		{
			//����Ĳ���
			p = (struct node*)malloc(sizeof(struct node));
			p->data = a;
			p->next = t->next;
			t->next = p;
			break;
		}
		t = t->next;
	}
	//��������
	t = head;
	while (t != NULL)
	{
		cout << t->data << " ";
		t = t->next;
	}
	system("pause");
	return 0;
}
