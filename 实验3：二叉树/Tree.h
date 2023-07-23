#pragma once
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <unordered_map>
#include "TreeNode.h"
#define N 10010
#define INF 0x3f3f3f3f
#define endl '\n'
using namespace std;

template<class T>
class Tree
{
private:
	TreeNode<T>* root; //树根
	int numOfNode; //节点数量
public:
	TreeNode<T>* stk[N]; //模拟栈
	TreeNode<T>* que[N]; //模拟队列
	//构造函数
	Tree()
	{
		root = NULL;
		numOfNode = 0;
	}
	//带参构造函数
	Tree(char s[])
	{
		root = NULL;
		numOfNode = 0;
		TreeNode<T>* p;
		int tp = -1, k;
		for (int i = 0; s[i] != '\0'; i++)
		{
			if (s[i] == '(')
			{
				stk[++tp] = p;
				k = 1;
			}
			else if (s[i] == ')')
			{
				tp--;
			}
			else if (s[i] == ',')
			{
				k = 2;
			}
			else
			{
				p = new TreeNode<T>(s[i]);
				if (root == NULL) root = p;
				else
				{
					if (k == 1) stk[tp]->left = p;
					if (k == 2) stk[tp]->right = p;
				}
				numOfNode++;
			}
		}
	}
	//析构函数
	~Tree()
	{
		root = NULL;
		numOfNode = 0;
	}
	//创建二叉树
	void createTree(char s[])
	{
		root = NULL;
		TreeNode<T>* p = NULL;
		int tp = -1, k;
		for (int i = 0; s[i] != '\0'; i++)
		{
			if (s[i] == '(')
			{
				stk[++tp] = p;
				k = 1;
			}
			else if (s[i] == ')')
			{
				tp--;
			}
			else if (s[i] == ',')
			{
				k = 2;
			}
			else
			{
				p = new TreeNode<T>(s[i]);
				if (root == NULL) root = p;
				else
				{
					if (k == 1) stk[tp]->left = p;
					if (k == 2) stk[tp]->right = p;
				}
				numOfNode++;
			}
		}
	}
	//根据前序和中序遍历序列生成二叉树
	TreeNode<T>* createTreeByPreIn(char pre[], char in[], int n)
	{
		int k;
		char* p;
		if (n <= 0) return NULL;
		TreeNode<T>* node = new TreeNode<T>(*pre);
		numOfNode++;
		for (p = in; p < in + n; p++)
		{
			if (*p == *pre) break;
		}
		k = p - in;
		node->left = createTreeByPreIn(pre + 1, in, k);
		node->right = createTreeByPreIn(pre + k + 1, p + 1, n - k - 1);
		return node;
	}
	void createTreeByPreAndIn(char pre[], char in[], int n)
	{
		root = createTreeByPreIn(pre, in, n);
	}
	//根据中序和后序遍历序列生成二叉树
	TreeNode<T>* createTreeByInPost(char in[], char post[], int n)
	{
		int k;
		char* p;
		char r;
		if (n <= 0) return NULL;
		r = *(post + n - 1);
		TreeNode<T>* node = new TreeNode<T>(r);
		numOfNode++;
		for (p = in; p < in + n; p++)
		{
			if (*p == r) break;
		}
		k = p - in;
		node->left = createTreeByInPost(in, post, k);
		node->right = createTreeByInPost(p + 1, post + k, n - k - 1);
		return node;
	}
	void createTreeByInAndPost(char in[], char post[], int n)
	{
		root = createTreeByInPost(in, post, n);
	}
	//获取根节点
	TreeNode<T>* getRoot()
	{
		return root;
	}
	//获取节点个数
	int getNumOfNode()
	{
		return numOfNode;
	}
	//前序遍历
	void preOrder(TreeNode<T>* node)
	{
		if (node != NULL)
		{
			cout << node->data;
			preOrder(node->left);
			preOrder(node->right);
		}
	}
	//中序遍历
	void inOrder(TreeNode<T>* node)
	{
		if (node != NULL)
		{
			inOrder(node->left);
			cout << node->data;
			inOrder(node->right);
		}
	}
	//后序遍历
	void postOrder(TreeNode<T>* node)
	{
		if (node != NULL)
		{
			postOrder(node->left);
			postOrder(node->right);
			cout << node->data;
		}
	}
	//前序遍历（栈）
	void preOrderByStack()
	{
		if (root == NULL) return;
		TreeNode<T>* p = root;
		int tp = -1;
		while (tp > -1 || p != NULL)
		{
			while (p != NULL)
			{
				cout << p->data;
				stk[++tp] = p;
				p = p->left;
				
			}
			if (tp > -1)
			{
				p = stk[tp--];
				p = p->right;
			}
		}
		cout << endl;
	}
	//中序遍历（栈）
	void inOrderByStack()
	{
		if (root == NULL) return;
		TreeNode<T>* p = root;
		int tp = -1;
		while (tp > -1 || p != NULL)
		{
			while (p != NULL)
			{
				stk[++tp] = p;
				p = p->left;
			}
			if (tp > -1)
			{
				p = stk[tp--];
				cout << p->data;
				p = p->right;
			}
		}
		cout << endl;
	}
	//后序遍历（栈）
	void postOrderByStack()
	{
		if (root == NULL) return;
		TreeNode<T>* p = root;
		TreeNode<T>* r;
		bool flag;
		int tp = -1;
		do
		{
			while (p != NULL)
			{
				stk[++tp] = p;
				p = p->left;
			}
			r = NULL;
			flag = true;
			while (tp > -1 && flag)
			{
				p = stk[tp];
				if (p->right == r)
				{
					cout << p->data;
					tp--;
					r = p;
				}
				else
				{
					p = p->right;
					flag = false;
				}
			}
		} while (tp > -1);
		cout << endl;
	}
	//层序遍历
	void levelOrder()
	{
		if (root == NULL) return;
		TreeNode<T>* tmp;
		int hh = 0, tt = -1;
		que[++tt] = root;
		while (hh <= tt)
		{
			tmp = que[hh++];
			cout << tmp->data;
			if (tmp->left != NULL) que[++tt] = tmp->left;
			if (tmp->right != NULL) que[++tt] = tmp->right;
		}
		cout << endl;
	}
	//找左子节点
	TreeNode<T>* leftChild(TreeNode<T>* node)
	{
		return node->left;
	}
	//找右子节点
	TreeNode<T>* rightChild(TreeNode<T>* node)
	{
		return node->right;
	}
	//节点的度
	int duOfNode(TreeNode<T>* node)
	{
		return (node->left != NULL) + (node->right != NULL);
	}
	//高度
	int heigh(TreeNode<T>* node)
	{
		if (node == NULL) return 0;
		int hl = 0, hr = 0;
		hl = heigh(node->left);
		hr = heigh(node->right);
		return max(hl, hr) + 1;
	}
	//翻转二叉树
	TreeNode<T>* invertTree(TreeNode<T>* node)
	{
		if (node == NULL) return NULL;
		TreeNode<T>* pLeft = invertTree(node->left);
		TreeNode<T>* pRight = invertTree(node->right);
		node->left = pRight;
		node->right = pLeft;
		return node;
	}
	//二叉树的最大深度
	int maxDepth(TreeNode<T>* node)
	{
		if (node == NULL) return 0;
		return max(maxDepth(node->left), maxDepth(node->right)) + 1;
	}
	//二叉树的最小深度
	int minDepth(TreeNode<T>* node)
	{
		if (node == NULL) return 0;
		if (node->left == NULL && node->right == NULL) return 1;
		int ans = INF;
		if (node->left != NULL) ans = min(minDepth(node->left), ans);
		if (node->right != NULL) ans = min(minDepth(node->right), ans);
		return ans + 1;
	}
	//输出二叉树
	void dispTree(TreeNode<T>* node)
	{
		if (node != NULL)
		{
			cout << node->data;
			if (node->left != NULL || node->right != NULL)
			{
				cout << '(';
				dispTree(node->left);
				if (node->right != NULL) cout << ',';
				dispTree(node->right);
				cout << ')';
			}
		}
	}
};