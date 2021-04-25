#pragma once
#include<algorithm>

template <typename Object>
class Vector
{
public:
	//���캯�������û�ָ����ʼ��С����Ĭ��ֵ��0
	//Ȼ���ñȴ�С�Դ�һЩ������ʼ�����ݳ�Ա����Щpush_back���øı��������ܱ�ִ��
	explicit Vector(int initSize = 0) :theSize{ initSize }, theCapacity{ initSize + SPACE_CAPACITY }
	{objects = new Object[theCapacity];}

	//�������캯������һ���µ�Vector����Ȼ������operator=�Ĳ������ʵ���У���������һ�θ������õ��˱�׼�Ľ�����ʽ
	//�����ʽֻͨ���ƶ���ɽ���ʱ��Ч��������Ҫ���ƶ����캯�����ƶ�operator=��ʵ��
	//ʹ�ÿ������캯���ͽ�����ʵ�ֵĿ�����ֵoperator=��Ȼ�򵥣���ȴ��������Ч�ķ������ر���������Vector�������ͬ���Ĵ�С�������
	//ʹ��Object��operator=ֱ���������ÿ��Ԫ�ظ���Ч
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

	//�ƶ����캯����ʵ��
	Vector(Vector&& rhs) :theSize{ rhs.theSize }, theCapacity{ rhs.theCapacity }, objects{ rhs.objects }
	{
		rhs.objects = nullptr;
		rhs.theSize = 0;
		rhs.theCapacity = 0;
	}

	//�ƶ�operator=��ʵ��
	Vector& operator=(Vector&& rhs)
	{
		std::swap(theSize, rhs.theSize);
		std::swap(theCapacity, rhs.theCapacity);
		std::swap(objects, rhs.objects);

		return *this;
	}

	//ֱ������theSize���ݳ�Ա�����п�������չ����֮�����
	void resize(int newSize)
	{
		if (newSize > theCapacity)
			reserve(newSize * 2);
		theSize = newSize;
	}

	//��չ����
	void reserve(int newCapacity)
	{
		//Ҳ�����������飬ֻ����ָ�������������ٺ�ԭ��С��ͬ������£����򱻺���
		if (newCapacity < theSize)
			return;

		//����������
		Object* newArray = new Object[newCapacity];
		//�ƶ�������
		for (int k = 0;k < theSize;k++)
			newArray[k] = std::move(objects[k]);

		theCapacity = newCapacity;
		std::swap(objects, newArray);
		//����������
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
	//Vector�Ѵ�С�������Լ�ԭʼ������Ϊ�����ݳ�Ա�洢
	int theSize;
	int theCapacity;
	Object* objects;
};

