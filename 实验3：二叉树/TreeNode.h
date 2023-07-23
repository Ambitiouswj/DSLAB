#pragma once
#include "Tree.h"

template<class T>
class TreeNode
{
public:
	char data; //数据
	TreeNode<T>* left; //左指针
	TreeNode<T>* right;//右指针
public:
	//构造函数
	TreeNode()
	{
		left = NULL;
		right = NULL;
	}
	//带参构造函数
	TreeNode(char data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}
	//析构函数
	~TreeNode()
	{
		left = NULL;
		right = NULL;
	}
};