#pragma once
#include "test_05.h"

struct TreeNode
{
	int data; // ����
	TreeNode* left; // ��ָ��
	TreeNode* right;// ��ָ��

	TreeNode()
	{
		data = 0;
		left = NULL;
		right = NULL;
	}
	//���ι��캯��
	TreeNode(int data)
	{
		this->data = data;
		left = NULL;
		right = NULL;
	}
	//��������
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
////���ι��캯��
//TreeNode::TreeNode(int data)
//{
//	this->data = data;
//	left = NULL;
//	right = NULL;
//}
////��������
//TreeNode::~TreeNode()
//{
//	left = NULL;
//	right = NULL;
//}