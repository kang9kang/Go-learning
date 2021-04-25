#include <iostream>
#include <string>
using namespace std;

class student
{
public:
	void Input() 
	{
		cin >> name >> score;
	}
	bool Compare(student stu1 ,student stu2)
	{
		return stu1.score < stu2.score;
	}
	void Output() 
	{
		cout << name << endl;
	}
private:
	string name;
	int score;
};

int main()
{
	student a[100], t;
	int i, j, n;
	cin >> n;
	for (i = 1;i <= n;i++)
	{
		a[i].Input();
	}
	for (i = 1;i <= n - 1;i++)
	{
		for (j = 1;j <= n - i;j++)
		{
			if (a[j].Compare(a[j], a[j + 1]))
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
	for (i = 1;i <= n;i++)
	{
		a[i].Output();
	}
	system("pause");
	return 0;
}