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
#include "ListNode.h"
#define endl '\n'
using namespace std;

template<class T>
class List
{
private:
	ListNode<T>* head;
	int numOfNode;
public:
	//���캯��
	List()
	{
		head = new ListNode<T>();
		head->next = NULL;
		numOfNode = 0;
	}
	//��������
	~List()
	{
		head = NULL;
	}
	//ͷ������
	void insertByHead(T elem)
	{
		ListNode<T>* newNode = new ListNode<T>(elem);
		newNode->next = head->next;
		head->next = newNode;
		numOfNode++;
	}
	//β������
	void insertByTail(T elem)
	{
		ListNode<T>* newNode = new ListNode<T>(elem);
		ListNode<T>* pMove = head;
		while (pMove->next != NULL)
		{
			pMove = pMove->next;
		}
		pMove->next = newNode;
		numOfNode++;
	}
	//ָ��λ��ǰ����
	bool insertByFrontPos(int pos, T elem)
	{
		if (pos <= 0 || pos > numOfNode) return false;
		ListNode<T>* newNode = new ListNode<T>(elem);
		ListNode<T>* posFrontNode = head;
		ListNode<T>* posNode = head->next;
		for (int i = 1; i < pos; i++)
		{
			posFrontNode = posNode;
			posNode = posNode->next;
		}
		newNode->next = posNode;
		posFrontNode->next = newNode;
		numOfNode++;
		return true;
	}
	//ָ��λ�ú����
	bool insertByBehindPos(int pos, T elem)
	{
		if (pos <= 0 || pos > numOfNode) return false;
		ListNode<T>* newNode = new ListNode<T>(elem);
		ListNode<T>* posNode = head->next;
		ListNode<T>* posBehindNode = posNode->next;
		for (int i = 1; i < pos; i++)
		{
			posNode = posBehindNode;
			posBehindNode = posBehindNode->next;
		}
		newNode->next = posBehindNode;
		posNode->next = newNode;
		numOfNode++;
		return true;
	}
	//ָ��Ԫ��ǰ����
	bool insertByFrontPosElem(T posElem, T elem)
	{
		ListNode<T>* newNode = new ListNode<T>(elem);
		ListNode<T>* posFrontNode = head;
		ListNode<T>* posNode = head->next;
		while (!(posNode->data == posElem) && posNode != NULL)
		{
			posFrontNode = posNode;
			posNode = posNode->next;
		}
		if (posNode == NULL) return false;
		else
		{
			newNode->next = posNode;
			posFrontNode->next = newNode;
		}
		numOfNode++;
		return true;
	}
	//ָ��Ԫ�غ����
	bool insertByBehindPosElem(T posElem, T elem)
	{
		ListNode<T>* newNode = new ListNode<T>(elem);
		ListNode<T>* posNode = head->next;
		ListNode<T>* posBehindNode = posNode->next;
		while (!(posNode->data == posElem) && posBehindNode != NULL)
		{
			posNode = posBehindNode;
			posBehindNode = posBehindNode->next;
		}
		if (posBehindNode == NULL && !(posNode->data == posElem)) return false;
		else
		{
			newNode->next = posBehindNode;
			posNode->next = newNode;
		}
		numOfNode++;
		return true;
	}
	//ɾ��ָ��λ��Ԫ��
	bool deleteByPos(int pos)
	{
		if (head->next == NULL || pos > numOfNode) return false;
		ListNode<T>* posFrontNode = head;
		ListNode<T>* posNode = head->next;
		for (int i = 1; i < pos; i++)
		{
			posFrontNode = posNode;
			posNode = posNode->next;
		}
		posFrontNode->next = posNode->next;
		delete posNode;
		posNode = NULL;
		numOfNode--;
		return true;
	}
	//ɾ��ָ��Ԫ��
	bool deleteByElem(T posElem)
	{
		if (head->next == NULL) return false;
		ListNode<T>* posFrontNode = head;
		ListNode<T>* posNode = head->next;
		while (posNode != NULL && !(posNode->data == posElem))
		{
			posFrontNode = posNode;
			posNode = posNode->next;
		}
		if (posNode == NULL) return false;
		else
		{
			posFrontNode->next = posNode->next;
			delete posNode;
			posNode = NULL;
		}
		numOfNode--;
		return true;
	}
	//����Ԫ��λ��
	int findElemPos(T posElem)
	{
		if (head->next == NULL) return -1;
		int pos = 1;
		ListNode<T>* pMove = head->next;
		while (pMove != NULL)
		{
			if (pMove->data == posElem) return pos;
			pos++;
		}
		return -1;
	}
	//����Ԫ��
	ListNode<T>* findElem(T posElem)
	{
		if (head->next == NULL) return NULL;
		ListNode<T>* pMove = head->next;
		while (pMove != NULL)
		{
			if (pMove->data == posElem) break;
			pMove = pMove->next;
		}
		return pMove;
	}
	//��ȡ�ڵ����
	int nodeNum()
	{
		return numOfNode;
	}
	//��������
	void sortList()
	{
		if (head->next == NULL) return;
		ListNode<T>* pMove = head->next->next;
		ListNode<T>* pFront;
		ListNode<T>* pTemp;
		head->next->next = NULL;
		while (pMove != NULL)
		{
			pTemp = pMove->next;
			pFront = head;
			while (pFront->next != NULL && pFront->next->data < pMove->data)
			{
				pFront = pFront->next;
			}
			pMove->next = pFront->next;
			pFront->next = pMove;
			pMove = pTemp;
		}
	}
	//��ת����
	void reverseList()
	{
		if (head->next == NULL) return;
		ListNode<T>* pFront = NULL;
		ListNode<T>* pMove = head->next;
		while (pMove != NULL)
		{
			ListNode<T>* temp = pMove->next;
			pMove->next = pFront;
			pFront = pMove;
			pMove = temp;
		}
		head->next = pFront;
	}
	//��ӡ����
	void printList()
	{
		if (head->next == NULL) return;
		ListNode<T>* pMove = head->next;
		while (pMove != NULL)
		{
			cout << pMove->data << ' ';
			pMove = pMove->next;
		}
		cout << endl;
	}
};