#pragma once
#include<algorithm>

template <typename Object>
class Vector
{
public:
	//构造函数允许用户指定初始大小，其默认值是0
	//然后用比大小稍大一些的数初始化数据成员，有些push_back不用改变容量就能被执行
	explicit Vector(int initSize = 0) :theSize{ initSize }, theCapacity{ initSize + SPACE_CAPACITY }
	{objects = new Object[theCapacity];}

	//拷贝构造函数构建一个新的Vector对象，然后被用在operator=的不经意的实现中，而后者再一次复制中用到了标准的交换定式
	//这个定式只通过移动完成交换时有效，它本身要求移动构造函数和移动operator=的实现
	//使用拷贝构造函数和交换所实现的拷贝赋值operator=虽然简单，但却不是最有效的方法，特别是在两个Vector对象具有同样的大小的情况下
	//使用Object的operator=直接逐个拷贝每个元素更有效
	Vector(const Vector& rhs) :theSize{ rhs.theSize }, theCapacity{ rhs.theCapacity }, objects{ nullptr }
	{
		objects = new Object[theCapacity];
		for (int k = 0;k < theSize;k++)
			objects[k] = rhs.objects[k];
	}

	Vector& operator=(const Vector& rhs)
	{
		Vector copy = rhs;
		std::swap(*this, copy);
		return *this;
	}

	~Vector()
	{
		delete[]objects;
	}

	//移动构造函数的实现
	Vector(Vector&& rhs) :theSize{ rhs.theSize }, theCapacity{ rhs.theCapacity }, objects{ rhs.objects }
	{
		rhs.objects = nullptr;
		rhs.theSize = 0;
		rhs.theCapacity = 0;
	}

	//移动operator=的实现
	Vector& operator=(Vector&& rhs)
	{
		std::swap(theSize, rhs.theSize);
		std::swap(theCapacity, rhs.theCapacity);
		std::swap(objects, rhs.objects);

		return *this;
	}

	//直接设置theSize数据成员，但有可能在扩展容量之后进行
	void resize(int newSize)
	{
		if (newSize > theCapacity)
			reserve(newSize * 2);
		theSize = newSize;
	}

	//扩展容量
	void reserve(int newCapacity)
	{
		//也可以收缩数组，只能在指定的新容量至少和原大小相同的情况下，否则被忽略
		if (newCapacity < theSize)
			return;

		//分配新数组
		Object* newArray = new Object[newCapacity];
		//移动老数据
		for (int k = 0;k < theSize;k++)
			newArray[k] = std::move(objects[k]);

		theCapacity = newCapacity;
		std::swap(objects, newArray);
		//回收老数据
		delete[]newArray;
	}

	Object& operator[](int index)
	{
		return objects[index];
	}
	const Object& operator[](int index)const
	{
		return objects[index];
	}

	bool empty()const
	{
		return size() == 0;
	}
	int size()const
	{
		return theSize;
	}
	int capacity()const
	{
		return theCapacity;
	}

	void push_back(const Object& x)
	{
		if (theSize == theCapacity)
			reserve(2 * theCapacity + 1);
		objects[theSize++] = x;
	}

	void push_back(Object&& x)
	{
		if (theSize == theCapacity)
			reserve(2 * theCapacity + 1);
		objects[theSize++] = std::move(x);
	}

	void  pop_back()
	{
		--theSize;
	}

	const Object& back()const
	{
		return objects[theSize - 1];
	}

	typedef Object* iterator;
	typedef const Object* const_iterator;

	iterator begin()
	{
		return &objects[0];
	}
	const_iterator begin()const
	{
		return &objects[0];
	}
	iterator end()
	{
		return &objects[size()];
	}
	const_iterator end()const
	{
		return &objects[size()];
	}

	static const int SPACE_CAPACITY = 16;

private:
	//Vector把大小、容量以及原始数组作为其数据成员存储
	int theSize;
	int theCapacity;
	Object* objects;
};

