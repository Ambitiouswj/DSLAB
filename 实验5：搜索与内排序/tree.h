#pragma once
#include "test_05.h"
#include "treenode.h"
#include <iostream>
#define N 10010
#define INF 0x3f3f3f3f
#define endl '\n'
using namespace std;

class Tree
{
private:
	TreeNode* root;
	int numOfNode;
public:
	Tree()
	{
		root = NULL;
		numOfNode = 0;
	}
	Tree(int p[], int n)
	{
		root = NULL;
		numOfNode = 0;
		for (int i = 0; i < n; i++)
		{
			root = insert(this->root, p[i]);
		}
	}
	//��������
	~Tree()
	{
		root = NULL;
		numOfNode = 0;
	}
	// ����ڵ�
	TreeNode* insert(TreeNode* node, int x)
	{
		if (node == NULL) node = new TreeNode(x), numOfNode++;
		else
		{
			if (x < node->data) node->left = insert(node->left, x);
			else if (x > node->data) node->right = insert(node->right, x);
		}
		return node;
	}
	// ɾ���ڵ�
	TreeNode* remove(TreeNode* node, int x)
	{
		TreeNode* p;
		if (node == NULL) return node;
		if (x < node->data) node->left = remove(node->left, x);
		else if (x > node->data) node->right = remove(node->right, x);
		else
		{
			if (node->left != NULL && node->right != NULL)
			{
				p = findMin(node->right);
				node->data = p->data;
				node->right = remove(node->right, node->data);
			}
			else
			{
				p = node;
				if (node->left != NULL) node = node->right;
				else node = node->left;
				delete p;
			}
		}
		return node;
	}
	// ����СԪ��
	TreeNode* findMin(TreeNode* node)
	{
		if (node == NULL) return NULL;
		if (node->left == NULL) return node;
		return findMin(node->left);
	}
	// �����Ԫ��
	TreeNode* findMax(TreeNode* node)
	{
		if (node != NULL)
		{
			while (node->right != NULL)
			{
				node = node->right;
			}
		}
		return node;
	}
	TreeNode* find(TreeNode* node, int x, int& cnt)
	{
		int len = 0;
		while (node != NULL)
		{
			len++;
			if (x < node->data) node = node->left;
			else if (x > node->data) node = node->right;
			else break;
		}
		cnt = len;
		return node;
	}
	//��ȡ���ڵ�
	TreeNode* getRoot()
	{
		return root;
	}
	//��ȡ�ڵ����
	int getNumOfNode()
	{
		return numOfNode;
	}
	//ǰ�����
	void preOrder(TreeNode* node)
	{
		if (node != NULL)
		{
			cout << node->data << ' ';
			preOrder(node->left);
			preOrder(node->right);
		}
	}
	//�������
	void inOrder(TreeNode* node)
	{
		if (node != NULL)
		{
			inOrder(node->left);
			cout << node->data << ' ';
			inOrder(node->right);
		}
	}
	//�������
	void postOrder(TreeNode* node)
	{
		if (node != NULL)
		{
			postOrder(node->left);
			postOrder(node->right);
			cout << node->data << ' ';
		}
	}
	void levelOrder()
	{
		TreeNode* que[100010];
		if (root == NULL) return;
		TreeNode* tmp;
		int hh = 0, tt = -1;
		que[++tt] = root;
		while (hh <= tt)
		{
			tmp = que[hh++];
			cout << tmp->data << ' ';
			if (tmp->left != NULL) que[++tt] = tmp->left;
			if (tmp->right != NULL) que[++tt] = tmp->right;
		}
		cout << endl;
	}
	
};


//Tree::Tree()
//{
//	root = NULL;
//	numOfNode = 0;
//}
//Tree::Tree(int p[], int n)
//{
//	root = NULL;
//	numOfNode = 0;
//	for (int i = 0; i < n; i++)
//	{
//		root = insert(this->root, p[i]);
//	}
//}
////��������
//Tree::~Tree()
//{
//	root = NULL;
//	numOfNode = 0;
//}
//// ����ڵ�
//TreeNode* Tree::insert(TreeNode* node, int x)
//{
//	if (node == NULL) node = new TreeNode(x), numOfNode++;
//	else
//	{
//		if (x < node->data) node->left = insert(node->left, x);
//		else if (x > node->data) node->right = insert(node->right, x);
//	}
//	return node;
//}
//// ɾ���ڵ�
//TreeNode* Tree::remove(TreeNode* node, int x)
//{
//	TreeNode* p;
//	if (node == NULL) return node;
//	if (x < node->data) node->left = remove(node->left, x);
//	else if (x > node->data) node->right = remove(node->right, x);
//	else
//	{
//		if (node->left != NULL && node->right != NULL)
//		{
//			p = findMin(node->right);
//			node->data = p->data;
//			node->right = remove(node->right, node->data);
//		}
//		else
//		{
//			p = node;
//			if (node->left != NULL) node = node->right;
//			else node = node->left;
//			delete p;
//		}
//	}
//	return node;
//}
//// ����СԪ��
//TreeNode* Tree::findMin(TreeNode* node)
//{
//	if (node == NULL) return NULL;
//	if (node->left == NULL) return node;
//	return findMin(node->left);
//}
//// �����Ԫ��
//TreeNode* Tree::findMax(TreeNode* node)
//{
//	if (node != NULL)
//	{
//		while (node->right != NULL)
//		{
//			node = node->right;
//		}
//	}
//	return node;
//}
//TreeNode* Tree::find(TreeNode* node, int x, int& cnt)
//{
//	int len = 0;
//	while (node != NULL)
//	{
//		len++;
//		if (x < node->data) node = node->left;
//		else if (x > node->data) node = node->right;
//		else break;
//	}
//	cnt = len;
//	return node;
//}
////��ȡ���ڵ�
//TreeNode* Tree::getRoot()
//{
//	return root;
//}
////��ȡ�ڵ����
//int Tree::getNumOfNode()
//{
//	return numOfNode;
//}
////ǰ�����
//void Tree::preOrder(TreeNode* node)
//{
//	if (node != NULL)
//	{
//		cout << node->data << ' ';
//		preOrder(node->left);
//		preOrder(node->right);
//	}
//}
////�������
//void Tree::inOrder(TreeNode* node)
//{
//	if (node != NULL)
//	{
//		inOrder(node->left);
//		cout << node->data << ' ';
//		inOrder(node->right);
//	}
//}
////�������
//void Tree::postOrder(TreeNode* node)
//{
//	if (node != NULL)
//	{
//		postOrder(node->left);
//		postOrder(node->right);
//		cout << node->data << ' ';
//	}
//}
//void Tree::levelOrder()
//{
//	TreeNode* que[100010];
//	if (root == NULL) return;
//	TreeNode* tmp;
//	int hh = 0, tt = -1;
//	que[++tt] = root;
//	while (hh <= tt)
//	{
//		tmp = que[hh++];
//		cout << tmp->data << ' ';
//		if (tmp->left != NULL) que[++tt] = tmp->left;
//		if (tmp->right != NULL) que[++tt] = tmp->right;
//	}
//	cout << endl;
//}