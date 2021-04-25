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
//将一幅扑克牌平均分成两份，每人一份。1拿出第一张放在桌子上，2拿出第一张放在1拿出的牌的上面，两人一次交替出牌。
//出牌时，若某人打出的牌桌子上存在，即可将两张相同的牌中间所夹的牌全部拿走，并依次放在自己的牌组末尾。
//当任意一人的手牌为零，游戏结束，对手获胜
int main()
{
	struct queue q1, q2;//队列  表示两人手牌
	struct stack s;//栈  表示桌子上的牌
	int book[10] = {0};//标签  桌子上有的牌
	int i, t;//控制循环的变量 临时变量

	//初始化队列和栈
	q1.head = 1;q1.tail = 1;
	q2.head = 1;q2.tail = 1;
	s.top = 0;
	
	//依次向队列里插入牌
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
	//游戏主循环，当有一人手里牌组为零则结束游戏
	while (q1.head < q1.tail && q2.head < q2.tail)
	{
		//q1打出一张牌
		t = q1.data[q1.head];
		if (book[t] == 0)//如果桌面上没有牌
		{
			book[t] = 1;
			s.top++;
			q1.head++;//出队
			s.data[s.top] = t;//入栈
		}
		else//如果桌面上有此牌
		{
			q1.head++;//出队
			q1.data[q1.tail] = t;//拿回
			q1.tail++;
			while (s.data[s.top]!=t)
			{
				book[s.data[s.top]] = 0;
				q1.data[q1.tail] = s.data[s.top];//出栈入队
				q1.tail++;
				s.top--;
			}
		}

		//q2打出一张牌
		t = q2.data[q2.head];
		if (book[t] == 0)//如果桌面上没有牌
		{
			book[t] = 1;
			s.top++;
			q2.head++;//出队
			s.data[s.top] = t;//入栈
		}
		else//如果桌面上有此牌
		{
			q2.head++;//出队
			q2.data[q2.tail] = t;//拿回
			q2.tail++;
			while (s.data[s.top] != t)
			{
				book[s.data[s.top]] = 0;
				q2.data[q2.tail] = s.data[s.top];//出栈入队
				q2.tail++;
				s.top--;
			}
			
		}
	}

	//如果有一人手牌为零
	if (q1.head == q1.tail)
	{
		cout << "q2 win" << endl;
		cout << "q2手中的牌为" << endl;
		for (i = q2.head;i < q2.tail;i++)
		{
			cout << q2.data[i] << " ";
		}
		if (s.top > 0)
		{
			cout << endl<< "桌上的牌有" << endl;
			for (i = 1;i <=s.top;i++)
			{
				cout << s.data[i] << " ";
			}
		}
		else
		{
			cout << "桌子上没有牌" << endl;
		}
	}
	else
	{
		cout << "q1 win" << endl;
		cout << "q1手中的牌为" << endl;
		for (i = q1.head;i < q1.tail;i++)
		{
			cout << q1.data[i] << " ";
		}
		if (s.top > 0)
		{
			cout <<endl<< "桌上的牌有" << endl;
			for (i = 1;i <=s.top;i++)
			{
				cout << s.data[i] << " ";
			}
		}
		else
		{
			cout << "桌子上没有牌" << endl;
		}
	}
	system("pause");
	return 0;
}