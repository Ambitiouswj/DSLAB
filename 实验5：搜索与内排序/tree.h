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
	//析构函数
	~Tree()
	{
		root = NULL;
		numOfNode = 0;
	}
	// 插入节点
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
	// 删除节点
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
	// 找最小元素
	TreeNode* findMin(TreeNode* node)
	{
		if (node == NULL) return NULL;
		if (node->left == NULL) return node;
		return findMin(node->left);
	}
	// 找最大元素
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
	//获取根节点
	TreeNode* getRoot()
	{
		return root;
	}
	//获取节点个数
	int getNumOfNode()
	{
		return numOfNode;
	}
	//前序遍历
	void preOrder(TreeNode* node)
	{
		if (node != NULL)
		{
			cout << node->data << ' ';
			preOrder(node->left);
			preOrder(node->right);
		}
	}
	//中序遍历
	void inOrder(TreeNode* node)
	{
		if (node != NULL)
		{
			inOrder(node->left);
			cout << node->data << ' ';
			inOrder(node->right);
		}
	}
	//后序遍历
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
////析构函数
//Tree::~Tree()
//{
//	root = NULL;
//	numOfNode = 0;
//}
//// 插入节点
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
//// 删除节点
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
//// 找最小元素
//TreeNode* Tree::findMin(TreeNode* node)
//{
//	if (node == NULL) return NULL;
//	if (node->left == NULL) return node;
//	return findMin(node->left);
//}
//// 找最大元素
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
////获取根节点
//TreeNode* Tree::getRoot()
//{
//	return root;
//}
////获取节点个数
//int Tree::getNumOfNode()
//{
//	return numOfNode;
//}
////前序遍历
//void Tree::preOrder(TreeNode* node)
//{
//	if (node != NULL)
//	{
//		cout << node->data << ' ';
//		preOrder(node->left);
//		preOrder(node->right);
//	}
//}
////中序遍历
//void Tree::inOrder(TreeNode* node)
//{
//	if (node != NULL)
//	{
//		inOrder(node->left);
//		cout << node->data << ' ';
//		inOrder(node->right);
//	}
//}
////后序遍历
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