#include <iostream>
using namespace std;

struct queue
{
	int data[1000];
	int head;
	int tail;
};

struct stack
{
	int data[10];
	int top;
};
//��һ���˿���ƽ���ֳ����ݣ�ÿ��һ�ݡ�1�ó���һ�ŷ��������ϣ�2�ó���һ�ŷ���1�ó����Ƶ����棬����һ�ν�����ơ�
//����ʱ����ĳ�˴�����������ϴ��ڣ����ɽ�������ͬ�����м����е���ȫ�����ߣ������η����Լ�������ĩβ��
//������һ�˵�����Ϊ�㣬��Ϸ���������ֻ�ʤ
int main()
{
	struct queue q1, q2;//����  ��ʾ��������
	struct stack s;//ջ  ��ʾ�����ϵ���
	int book[10] = {0};//��ǩ  �������е���
	int i, t;//����ѭ���ı��� ��ʱ����

	//��ʼ�����к�ջ
	q1.head = 1;q1.tail = 1;
	q2.head = 1;q2.tail = 1;
	s.top = 0;
	
	//����������������
	for (i = 1;i <= 6;i++)
	{
		cin >> q1.data[q1.tail];
		q1.tail++;
	}
	for (i = 1;i <= 6;i++)
	{
		cin >> q2.data[q2.tail];
		q2.tail++;
	}
	//��Ϸ��ѭ��������һ����������Ϊ���������Ϸ
	while (q1.head < q1.tail && q2.head < q2.tail)
	{
		//q1���һ����
		t = q1.data[q1.head];
		if (book[t] == 0)//���������û����
		{
			book[t] = 1;
			s.top++;
			q1.head++;//����
			s.data[s.top] = t;//��ջ
		}
		else//����������д���
		{
			q1.head++;//����
			q1.data[q1.tail] = t;//�û�
			q1.tail++;
			while (s.data[s.top]!=t)
			{
				book[s.data[s.top]] = 0;
				q1.data[q1.tail] = s.data[s.top];//��ջ���
				q1.tail++;
				s.top--;
			}
		}

		//q2���һ����
		t = q2.data[q2.head];
		if (book[t] == 0)//���������û����
		{
			book[t] = 1;
			s.top++;
			q2.head++;//����
			s.data[s.top] = t;//��ջ
		}
		else//����������д���
		{
			q2.head++;//����
			q2.data[q2.tail] = t;//�û�
			q2.tail++;
			while (s.data[s.top] != t)
			{
				book[s.data[s.top]] = 0;
				q2.data[q2.tail] = s.data[s.top];//��ջ���
				q2.tail++;
				s.top--;
			}
			
		}
	}

	//�����һ������Ϊ��
	if (q1.head == q1.tail)
	{
		cout << "q2 win" << endl;
		cout << "q2���е���Ϊ" << endl;
		for (i = q2.head;i < q2.tail;i++)
		{
			cout << q2.data[i] << " ";
		}
		if (s.top > 0)
		{
			cout << endl<< "���ϵ�����" << endl;
			for (i = 1;i <=s.top;i++)
			{
				cout << s.data[i] << " ";
			}
		}
		else
		{
			cout << "������û����" << endl;
		}
	}
	else
	{
		cout << "q1 win" << endl;
		cout << "q1���е���Ϊ" << endl;
		for (i = q1.head;i < q1.tail;i++)
		{
			cout << q1.data[i] << " ";
		}
		if (s.top > 0)
		{
			cout <<endl<< "���ϵ�����" << endl;
			for (i = 1;i <=s.top;i++)
			{
				cout << s.data[i] << " ";
			}
		}
		else
		{
			cout << "������û����" << endl;
		}
	}
	system("pause");
	return 0;
}