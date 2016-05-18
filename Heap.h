#include<iostream>
#include<vector>
using namespace std;

template<class T>
struct Less//С��
{
	bool operator()(const T&l,const T&r)
	{
	return l<r;
	}
};

template<class T>
struct Greater
{
	bool operator()(const T&l,const T&r)
	{
	return l>r;
	}
};
template<class T,class Comper=Greater<T>>//Ĭ�Ͻ����
class Heap
{
private:
	vector<T> _a;
public:

	Heap(const T* a,size_t size)
	{
		assert(a);
		//�������е�����ѹ��ջ��
		for(i=0;i<size;i++)
		{
		_a.push_back(a[i]);
		}
		//�����
		for(int i=(_a.size()-2)/2;i>=0;i--)
		{
		//���µ���
		_AdjustDown(i);
		}
	}
	//����в�������
	void push(const T& x)
	{
	_a.push_back (x);
	_Adjustup(_a.size()-1)
	}
/********************
�ڵ�����ʱ��ʹ�õķ�����
�Ƚ���ȫ�������ĸ��ڵ������һ��Ҷ�ӽڵ㽻����
������ǰ��Ҷ�ӽڵ�,Ȼ�������µ���
************************/
	void pop()
	{
	swap(_a[0],_a[_a.size()-1]);
	_a.pop_back ();
	_AdjustDown(0);
	}
	size_t Size()//��ѵĴ�С
	{
	  return _a.size();
	}

	bool Empty()//���Ƿ�Ϊ��
	{
	return _a.empty();
	}
protected:
	void _AdjustDown(size_t parent)
	{
		size_t child=2*parent+1;
		while(child<_a.size())
		{
			Comper com;
			//�ҳ���������������һ��
			if(com(_a[child+1],_a[child]) && child+1<_a.size())//��Ϊ����ȫ�����������Һ��ӿ��ܲ�����
			{
			child=child+1;
			}
			//������Ӵ��ڸ����򽻻��������µ���
			if(com(_a[child],_a[parent]))
			{
			swap(_a[child],_a[parent]);
			parent=child;
			child=2*parent+1;
			}
			//�����������ѣ��˳�ѭ��
			else
			{
			break;
			}
		}
	
	}

	//���ϵ���
	void _Adjustup(size_t child)
	{
		 size_t parent=(child-1)/2;
		 while(child>0)//����д��while(parent>0),��ΪchildΪsize_t ���ͣ��ṹ����ѭ��
		 {
			 Comper com;
			 //���������ӽڵ���ڸ��ڵ㣬�򽻻�
			 if(com(_a[child],_a[parent]))
			 {
			 swap(_a[child],_a[parent]);
			 child=parent;
			 parent=(child-1)/2;
			 }
			 //���������ѣ��˳�ѭ��
			 else
			 {
			 break;
			 }
		 }
	}
};