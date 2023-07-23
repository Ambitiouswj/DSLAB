#pragma once
#include "Tree.h"

template<class T>
class TreeNode
{
public:
	char data; //����
	TreeNode<T>* left; //��ָ��
	TreeNode<T>* right;//��ָ��
public:
	//���캯��
	TreeNode()
	{
		left = NULL;
		right = NULL;
	}
	//���ι��캯��
	TreeNode(char data)
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