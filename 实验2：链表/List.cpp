#include "List.h"
#include "ListNode.h"

//template<class T>
//List<T>::List()
//{
//	head = new ListNode<T>();
//	head->next = NULL;
//}
//
//template<class T>
//List<T>::~List()
//{
//	head = NULL;
//}
//
//template<class T>
//void List<T>::insertByHead(T elem)
//{
//	ListNode<T>* newNode = new ListNode<T>(elem);
//	newNode->next = head->next;
//	head->next = newNode;
//}
//
//template<class T>
//void List<T>::insertByTail(T elem)
//{
//	ListNode<T>* newNode = new ListNode<T>(elem);
//	ListNode<T>* pMove = head;
//	while (pMove->next != NULL)
//	{
//		pMove = pMove->next;
//	}
//	pMove->next = newNode;
//}
// 
//template<class T>
//bool List<T>::deleteByElem(T posElem)
//{
//	ListNode<T>* posFrontNode = head;
//	ListNode<T>* posNode = head->next;
//	while (posNode != NULL && posNode->data != posElem)
//	{
//		posFrontNode = posNode;
//		posNode = posNode->next;
//	}
//	if (posNode == NULL) return false;
//	else
//	{
//		posFrontNode->next = posNode->next;
//		delete posNode;
//		posNode = NULL;
//	}
//	return true;
//}
//
//template<class T>
//void List<T>::printList()
//{
//	ListNode<T>* pMove = head->next;
//	while (pMove != NULL)
//	{
//		cout << pMove->data << ' ';
//		pMove = pMove->next;
//	}
//	cout << endl;
//}