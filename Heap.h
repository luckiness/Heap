#include<iostream>
#include<vector>
using namespace std;

template<class T>
struct Less//小于
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
template<class T,class Comper=Greater<T>>//默认建大堆
class Heap
{
private:
	vector<T> _a;
public:

	Heap(const T* a,size_t size)
	{
		assert(a);
		//将数组中的数据压入栈中
		for(i=0;i<size;i++)
		{
		_a.push_back(a[i]);
		}
		//建大堆
		for(int i=(_a.size()-2)/2;i>=0;i--)
		{
		//向下调整
		_AdjustDown(i);
		}
	}
	//向堆中插入数据
	void push(const T& x)
	{
	_a.push_back (x);
	_Adjustup(_a.size()-1)
	}
/********************
在弹出的时候使用的方法是
先将完全二叉树的根节点与最后一个叶子节点交换，
弹出当前的叶子节点,然后在向下调整
************************/
	void pop()
	{
	swap(_a[0],_a[_a.size()-1]);
	_a.pop_back ();
	_AdjustDown(0);
	}
	size_t Size()//求堆的大小
	{
	  return _a.size();
	}

	bool Empty()//堆是否为空
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
			//找出两个孩子中最大的一个
			if(com(_a[child+1],_a[child]) && child+1<_a.size())//因为是完全二叉树所以右孩子可能不存在
			{
			child=child+1;
			}
			//如果孩子大于父亲则交换继续往下调整
			if(com(_a[child],_a[parent]))
			{
			swap(_a[child],_a[parent]);
			parent=child;
			child=2*parent+1;
			}
			//否则满足大根堆，退出循环
			else
			{
			break;
			}
		}
	
	}

	//向上调整
	void _Adjustup(size_t child)
	{
		 size_t parent=(child-1)/2;
		 while(child>0)//不能写成while(parent>0),因为child为size_t 类型，会构成死循环
		 {
			 Comper com;
			 //如果插入的子节点大于根节点，则交换
			 if(com(_a[child],_a[parent]))
			 {
			 swap(_a[child],_a[parent]);
			 child=parent;
			 parent=(child-1)/2;
			 }
			 //否则满足大堆，退出循环
			 else
			 {
			 break;
			 }
		 }
	}
};