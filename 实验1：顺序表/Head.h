#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#define endl '\n'
using namespace std;

template<class T>
class SqList
{
private:
    T* data;
    int MaxSize;
    int leng;
public:
    SqList();
    SqList(int size);
    //尾部插入
    bool pushBack(T obj);
    //指定位置前插入
    bool insertByFront(T obj, int pos);
    //指定位置后插入
    bool insertByBehind(T obj, int pos);
    //指定元素前插入
    bool insertByFrontElem(T obj, T pos);
    //指定元素后插入
    bool insertByBehindElem(T obj, T pos);
    //删除指定位置元素
    bool deleteByPos(int pos);
    //删除指定元素
    bool deleteByElem(T obj);
    //顺序表长度
    int lengthOfList();
    //清空线性表
    bool clearList();
    //打印线性表
    void printList();
    //是否为空
    bool isEmpty();
    //查找指定位置元素
    bool searchByPos(int pos, T& obj);
    //查找元素位置
    bool searchByElem(int& idx, T obj);
    //修改指定位置元素
    bool alter(int pos, T obj);
    //排序
    void sortList(int l, int r);
    ~SqList();
};

template<class T>
SqList<T>::SqList()
{
    data = NULL;
    leng = 0;
}

template<class T>
SqList<T>::SqList(int size)
{
    leng = 0;
    data = new T[size + 5];
    this->MaxSize = size;
}

//尾部添加
template<class T>
bool SqList<T>::pushBack(T obj)
{
    if (leng == MaxSize) return false;
    data[++leng] = obj;
    return true;
}

//指定位置前插入
template<class T>
bool SqList<T>::insertByFront(T obj, int pos)
{
    if (pos <= 0 || pos > leng || leng == MaxSize) return false;
    for (int i = leng; i >= pos; i--)
    {
        data[i + 1] = data[i];
    }
    data[pos] = obj;
    leng++;
    return true;
}

//指定位置后插入
template<class T>
bool SqList<T>::insertByBehind(T obj, int pos)
{
    if (pos <= 0 || pos > leng || leng == MaxSize) return false;
    for (int i = leng; i > pos; i--)
    {
        data[i + 1] = data[i];
    }
    data[pos + 1] = obj;
    leng++;
    return true;
}

//指定元素前插入
template<class T>
bool SqList<T>::insertByFrontElem(T obj, T pos)
{
    if (leng == MaxSize) return false;
    for (int i = 1; i <= leng; i++)
    {
        if (data[i] == pos)
        {
            for (int j = leng; j >= i; j--)
            {
                data[j + 1] = data[j];
            }
            data[i] = obj;
            leng++;
            return true;
        }
    }
    return false;
}

//指定元素后插入
template<class T>
bool SqList<T>::insertByBehindElem(T obj, T pos)
{
    if (leng == MaxSize) return false;
    for (int i = 1; i <= leng; i++)
    {
        if (data[i] == pos)
        {
            for (int j = leng; j > i; j--)
            {
                data[j + 1] = data[j];
            }
            data[i + 1] = obj;
            leng++;
            return true;
        }
    }
    return false;
}

//删除指定位置元素
template<class T>
bool SqList<T>::deleteByPos(int pos)
{
    if (pos <= 0 || pos > leng) return false;
    for (int i = pos; i <= leng - 1; i++)
    {
        data[i] = data[i + 1];
    }
    leng--;
    return true;
}
//删除指定元素
template<class T>
bool SqList<T>::deleteByElem(T obj)
{
    for (int i = 1; i <= leng; i++)
    {
        if (data[i] == obj)
        {
            for (int j = i; j < leng; j++)
            {
                data[j] = data[j + 1];
            }
            leng--;
            return true;
        }
    }
    return false;
}
//顺序表长度
template<class T>
int SqList<T>::lengthOfList()
{
    return leng;
}

//清空线性表
template<class T>
bool SqList<T>::clearList()
{
    leng = 0;
}
//打印线性表
template<class T>
void SqList<T>::printList()
{
    for (int i = 1; i <= leng; i++)
    {
        cout << data[i];
    }
    cout << endl;
}
//是否为空
template<class T>
bool SqList<T>::isEmpty()
{
    return leng == 0;
}

//查找指定位置元素
template<class T>
bool SqList<T>::searchByPos(int pos, T& obj)
{
    if (pos <= 0 || pos > leng) return false;
    obj = data[pos];
    return true;
}

//查找元素位置
template<class T>
bool SqList<T>::searchByElem(int& idx, T obj)
{
    for (int i = 1; i <= leng; i++)
    {
        if (data[i] == obj)
        {
            idx = i;
            return true;
        }
    }
    return false;
}

//修改指定位置元素
template<class T>
bool SqList<T>::alter(int pos, T obj)
{
    if (pos <= 0 || pos > leng) return false;
    data[pos] = obj;
    return true;
}

//排序
template<class T>
void SqList<T>::sortList(int l, int r)
{
    if (l >= r) return;
    T x = data[l + r >> 1];
    int i = l - 1, j = r + 1;
    while (i < j)
    {
        do i++; while (data[i] < x);
        do j--; while (data[j] > x);
        if (i < j) swap(data[i], data[j]);
    }
    sortList(l, j);
    sortList(j + 1, r);
}

template<class T>
SqList<T>::~SqList()
{
    delete[]data;
}