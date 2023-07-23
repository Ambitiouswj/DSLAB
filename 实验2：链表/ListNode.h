#pragma once
#include "List.h"

template<class T>
class ListNode
{
public:
	T data;
	ListNode<T>* next;
public:
	//���캯��
	ListNode()
	{
		next = NULL;
	}
	//���ι��캯��
	ListNode(T data)
	{
		this->data = data;
		next = NULL;
	}
	//��������
	~ListNode()
	{
		next = NULL;
	}
};

