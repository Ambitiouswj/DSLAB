#pragma once
#include "test_05.h"

int temp[100010];

void insert_sort(int p[], int n)
{                    
	int temp, pos;                 
	for (int i = 1; i < n; i++)                  
	{
		temp = p[i];                  
		pos = i - 1;                      
		while (pos >= 0 && temp < p[pos])  
		{
			p[pos + 1] = p[pos];     
			pos--;
		}
		p[pos + 1] = temp;
	}
}

void bubble_sort(int p[], int n)
{            
	for (int i = 1; i <= n - 1; i++)          
	{
		for (int j = 0; j < n - i; j++)      
		{
			if (p[j] > p[j + 1])   
			{
				int temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
}

void quick_sort(int p[], int l, int r)
{
	if (l >= r) return;
	int x = p[l + r >> 1];
	int i = l - 1, j = r + 1;
	while (i < j)
	{
		do i++; while (p[i] < x);
		do j--; while (p[j] > x);
		if (i < j)
		{
			int temp = p[i];
			p[i] = p[j];
			p[j] = temp;
		}
	}
	quick_sort(p, l, j);
	quick_sort(p, j + 1, r);
}

void merge_sort(int p[], int l, int r)
{
	if (l >= r) return;
	int mid= l + r >> 1;
	merge_sort(p, l, mid);
	merge_sort(p, mid + 1, r);

	int k = 0, i = l, j = mid + 1;
	while (i <= mid && j <= r)
	{
		if (p[i] <= p[j]) temp[k++] = p[i++];
		else temp[k++] = p[j++];
	}
	while (i <= mid) temp[k++] = p[i++];
	while (j <= r) temp[k++] = p[j++];
	for (int i = l, j = 0; i <= r; i++, j++)
	{
		p[i] = temp[j];
	}
}