#pragma once
#include "test_05.h"

struct TreeNode
{
	int data; // 数据
	TreeNode* left; // 左指针
	TreeNode* right;// 右指针

	TreeNode()
	{
		data = 0;
		left = NULL;
		right = NULL;
	}
	//带参构造函数
	TreeNode(int data)
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

//TreeNode::TreeNode()
//{
//	data = 0;
//	left = NULL;
//	right = NULL;
//}
////带参构造函数
//TreeNode::TreeNode(int data)
//{
//	this->data = data;
//	left = NULL;
//	right = NULL;
//}
////析构函数
//TreeNode::~TreeNode()
//{
//	left = NULL;
//	right = NULL;
//}