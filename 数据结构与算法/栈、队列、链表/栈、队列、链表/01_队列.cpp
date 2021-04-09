#include<iostream>
using namespace std;
struct queue
{
	int data[100];
	int head;
	int tail;
};
int main() 
{
	struct queue q;
	int i;
	q.head = 1;
	q.tail = 1;
	for (i = 1;i <= 9;i++)
	{
		cin >> q.data[q.tail++];
	}

	while (q.head < q.tail)
	{
		cout << q.data[q.head++];
		q.data[q.tail++] = q.data[q.head++];

	}
	system("pause");
	return 0;
}