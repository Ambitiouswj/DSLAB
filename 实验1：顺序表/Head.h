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
    //β������
    bool pushBack(T obj);
    //ָ��λ��ǰ����
    bool insertByFront(T obj, int pos);
    //ָ��λ�ú����
    bool insertByBehind(T obj, int pos);
    //ָ��Ԫ��ǰ����
    bool insertByFrontElem(T obj, T pos);
    //ָ��Ԫ�غ����
    bool insertByBehindElem(T obj, T pos);
    //ɾ��ָ��λ��Ԫ��
    bool deleteByPos(int pos);
    //ɾ��ָ��Ԫ��
    bool deleteByElem(T obj);
    //˳�����
    int lengthOfList();
    //������Ա�
    bool clearList();
    //��ӡ���Ա�
    void printList();
    //�Ƿ�Ϊ��
    bool isEmpty();
    //����ָ��λ��Ԫ��
    bool searchByPos(int pos, T& obj);
    //����Ԫ��λ��
    bool searchByElem(int& idx, T obj);
    //�޸�ָ��λ��Ԫ��
    bool alter(int pos, T obj);
    //����
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

//β�����
template<class T>
bool SqList<T>::pushBack(T obj)
{
    if (leng == MaxSize) return false;
    data[++leng] = obj;
    return true;
}

//ָ��λ��ǰ����
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

//ָ��λ�ú����
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

//ָ��Ԫ��ǰ����
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

//ָ��Ԫ�غ����
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

//ɾ��ָ��λ��Ԫ��
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
//ɾ��ָ��Ԫ��
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
//˳�����
template<class T>
int SqList<T>::lengthOfList()
{
    return leng;
}

//������Ա�
template<class T>
bool SqList<T>::clearList()
{
    leng = 0;
}
//��ӡ���Ա�
template<class T>
void SqList<T>::printList()
{
    for (int i = 1; i <= leng; i++)
    {
        cout << data[i];
    }
    cout << endl;
}
//�Ƿ�Ϊ��
template<class T>
bool SqList<T>::isEmpty()
{
    return leng == 0;
}

//����ָ��λ��Ԫ��
template<class T>
bool SqList<T>::searchByPos(int pos, T& obj)
{
    if (pos <= 0 || pos > leng) return false;
    obj = data[pos];
    return true;
}

//����Ԫ��λ��
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

//�޸�ָ��λ��Ԫ��
template<class T>
bool SqList<T>::alter(int pos, T obj)
{
    if (pos <= 0 || pos > leng) return false;
    data[pos] = obj;
    return true;
}

//����
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