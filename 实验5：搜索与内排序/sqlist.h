#pragma once
#include "test_05.h"
#define endl '\n'
#include <iostream>
using namespace std;

class SQList
{
private:
	int* data;
	int num;
public:
	SQList()
	{
		data = new int[0x7f];
		num = 0;
	}
	SQList(int p[],int n)
	{
		data = new int[n];
		num = n;
		for (int i = 0; i < n; i++)
		{
			data[i] = p[i];
		}
	}
	~SQList()
	{
		delete[] data;
	}
	// 快速排序
	void quick_sort(int l, int r)
	{
		if (l >= r) return;
		int x = data[l + r >> 1];
		int i = l - 1, j = r + 1;
		while (i < j)
		{
			do i++; while (data[i] < x);
			do j--; while (data[j] > x);
			if (i < j)
			{
				int temp = data[i];
				data[i] = data[j];
				data[j] = temp;
			}
		}
		quick_sort(l, j);
		quick_sort(j + 1, r);
	}
	// 二分查找
	int find(int x, int& cnt)
	{
		int len = 0;
		int l = 0, r = num - 1;
		int mid = 0;
		while (l < r)
		{
			mid = l + r >> 1;
			len++;
			if (data[mid] > x) r = mid - 1;
			else if (data[mid] < x) l = mid + 1;
			else break;
		}
		cnt = len;
		if (data[mid] == x) return mid;
		else return -1;
	}
	int getNum()
	{
		return num;
	}
	void print()
	{
		for (int i = 0; i < num; i++)
		{
			cout << data[i] << endl;
		}
		cout << endl;
	}
};

//SQList::SQList()
//{
//	data = new int[0x7f];
//	num = 0;
//}
//SQList::SQList(int p[], int n)
//{
//	data = new int[n];
//	num = n;
//	for (int i = 0; i < n; i++)
//	{
//		data[i] = p[i];
//	}
//}
//SQList::~SQList()
//{
//	delete[] data;
//}
//// 快速排序
//void SQList::quick_sort(int l, int r)
//{
//	if (l >= r) return;
//	int x = data[l + r >> 1];
//	int i = l - 1, j = r + 1;
//	while (i < j)
//	{
//		do i++; while (data[i] < x);
//		do j--; while (data[j] > x);
//		if (i < j)
//		{
//			int temp = data[i];
//			data[i] = data[j];
//			data[j] = temp;
//		}
//	}
//	quick_sort(l, j);
//	quick_sort(j + 1, r);
//}
//// 二分查找
//int SQList::find(int x, int& cnt)
//{
//	int len = 0;
//	int l = 0, r = num - 1;
//	int mid = 0;
//	while (l < r)
//	{
//		mid = l + r >> 1;
//		len++;
//		if (data[mid] > x) r = mid - 1;
//		else if (data[mid] < x) l = mid + 1;
//		else break;
//	}
//	cnt = len;
//	if (data[mid] == x) return mid;
//	else return -1;
//}
//int SQList::getNum()
//{
//	return num;
//}
//void SQList::print()
//{
//	for (int i = 0; i < num; i++)
//	{
//		cout << data[i] << endl;
//	}
//	cout << endl;
//}