#pragma once
#include "List.h"

template<class T>
class ListNode
{
public:
	T data;
	ListNode<T>* next;
public:
	//构造函数
	ListNode()
	{
		next = NULL;
	}
	//带参构造函数
	ListNode(T data)
	{
		this->data = data;
		next = NULL;
	}
	//析构函数
	~ListNode()
	{
		next = NULL;
	}
};

