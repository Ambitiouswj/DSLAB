#include "Head.h"
#include "student.h"

void testByClass() 
{
    SqList<Student> list2(20);
    list2.pushBack(Student("����", "63210506", 97, 87, 60));
    list2.pushBack(Student("����", "63210501", 93, 65, 86));
    list2.pushBack(Student("����", "63210509", 90, 20, 53));
    list2.pushBack(Student("����", "63210505", 91, 66, 81));
    Student s1("����", "12123", 65, 98, 64);
    Student s2("����", "63210506", 97, 87, 60);
    Student s3("����", "63210505", 91, 66, 81);
    cout << "���Student����" << endl;
    list2.printList();
    cout << "���ĺ����Student����" << endl;
    list2.insertByBehindElem(s2, s1);
    list2.printList();
    cout << "����ǰ����Student����" << endl;
    list2.insertByFrontElem(s3, s1);
    list2.printList();
    cout << "�������" << endl;
    list2.sortList(1, list2.lengthOfList());
    list2.printList();
    cout << "ɾ������" << endl;
    list2.deleteByElem(s1);
    list2.printList();
}

void testByInt()
{
    SqList<int> list1(1000);
    cout << "β������ | 1��3��5" << endl;
    list1.pushBack(1);
    list1.pushBack(3);
    list1.pushBack(5);
    cout << "ָ��Ԫ��ǰ���� | 5ǰ�����0" << endl;
    list1.insertByFrontElem(0, 5);
    cout << "ָ��Ԫ�غ���� | 3�������4" << endl;
    list1.insertByBehindElem(4, 3);
    cout << "��һ�δ�ӡ" << endl;
    list1.printList();
    cout << "��������" << endl;
    list1.sortList(1, list1.lengthOfList());
    cout << "�ڶ��δ�ӡ" << endl;
    list1.printList();
    cout << "ɾ��2��λ��Ԫ��" << endl;
    list1.deleteByPos(2);
    cout << "ɾ��Ԫ�أ�5" << endl;
    list1.deleteByElem(5);
    cout << "�����δ�ӡ" << endl;
    list1.printList();
    int x;
    cout << "��ȡ2��λ��Ԫ��" << endl;
    list1.searchByPos(2, x);
    cout << x << endl;
    cout << "����Ԫ��0��λ��" << endl;
    list1.searchByElem(x, 0);
    cout << x << endl;
    cout << "��3��λ�õ�Ԫ�ظ�Ϊ9" << endl;
    list1.alter(3, 9);
    list1.printList();
}

void testByFile()
{
    ifstream ifs("����.in");
    ofstream cout("����.out");
    SqList<int> list1(1000);
    cout << "β������ | 1��3��5" << endl;
    int a, b, c, d, e, f;
    ifs >> a >> b >> c >> d >> e >> f;
    list1.pushBack(a);
    list1.pushBack(b);
    list1.pushBack(c);
    cout << "ָ��Ԫ��ǰ���� | 5ǰ�����0" << endl;
    list1.insertByFrontElem(0, d);
    cout << "ָ��Ԫ�غ���� | 3�������4" << endl;
    list1.insertByBehindElem(4, e);
    cout << "��һ�δ�ӡ" << endl;
    list1.printList();
    cout << "��������" << endl;
    list1.sortList(1, list1.lengthOfList());
    cout << "�ڶ��δ�ӡ" << endl;
    list1.printList();
    cout << "ɾ��2��λ��Ԫ��" << endl;
    list1.deleteByPos(2);
    cout << "ɾ��Ԫ�أ�5" << endl;
    list1.deleteByElem(5);
    cout << "�����δ�ӡ" << endl;
    list1.printList();
    int x;
    cout << "��ȡ2��λ��Ԫ��" << endl;
    list1.searchByPos(2, x);
    cout << x << endl;
    cout << "����Ԫ��0��λ��" << endl;
    list1.searchByElem(x, 0);
    cout << x << endl;
    cout << "��3��λ�õ�Ԫ�ظ�Ϊ9" << endl;
    list1.alter(3, f);
    list1.printList();
    ifs.close();
    cout.close();
}

int main()
{
    testByInt();
    return 0;
}
