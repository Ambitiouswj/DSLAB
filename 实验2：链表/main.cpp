#include "List.h"
#include "ListNode.h"
#include "student.h"

void testByInt()
{
	List<int> list1;
	cout << "β������1,2,3,4��" << endl;
	list1.insertByTail(1);
	list1.insertByTail(2);
	list1.insertByTail(3);
	list1.insertByTail(4);
	cout << "ͷ������9��" << endl;
	list1.insertByHead(9);
	cout << "��һ�δ�ӡ��" << endl;
	list1.printList();
	cout << "1��λ��ǰ����8��" << endl;
	list1.insertByFrontPos(1, 8);
	cout << "4��λ�ú����0��" << endl;
	list1.insertByBehindPos(4, 0);
	cout << "Ԫ��4ǰ����8��" << endl;
	list1.insertByFrontPosElem(4, 8);
	cout << "Ԫ��2�����0��" << endl;
	list1.insertByBehindPosElem(2, 0);
	cout << "�ڶ��δ�ӡ��" << endl;
	list1.printList();
	cout << "��ת����" << endl;
	list1.reverseList();
	cout << "���Ĵδ�ӡ��" << endl;
	list1.printList();
	cout << "����" << endl;
	list1.sortList();
	cout << "����δ�ӡ��" << endl;
	list1.printList();
	cout << "ɾ��Ԫ��2��" << endl;
	list1.deleteByElem(2);
	cout << "�����δ�ӡ��" << endl;
	list1.printList();
}

void testByStudent()
{
	List<Student> list2;
	list2.insertByTail(Student("����", "63210506", 97, 87, 60));
	list2.insertByTail(Student("����", "63210501", 93, 65, 86));
	list2.insertByTail(Student("����", "63210509", 90, 20, 53));
	list2.insertByHead(Student("����", "63210505", 91, 66, 81));
	Student s1("����", "12120003", 65, 98, 64);
	Student s2("����", "63210506", 97, 87, 60);
	Student s3("����", "63210505", 91, 66, 81);
	cout << "���Student����" << endl;
	list2.printList();
	cout << "���ĺ����Student����" << endl;
	list2.insertByBehindPosElem(s2, s1);
	list2.printList();
	cout << "����ǰ����Student����" << endl;
	list2.insertByFrontPosElem(s3, s1);
	list2.printList();
	cout << "�������" << endl;
	list2.sortList();
	list2.printList();
	cout << "��ת����" << endl;
	list2.reverseList();
	list2.printList();
	cout << "ɾ������" << endl;
	list2.deleteByElem(s3);
	list2.printList();
}

void testByFile()
{
	ifstream cin("test.in");
	ofstream cout("test.out",ios::app);
	List<int> list1;
	int a, b, c, d, e, f, g, h, i, j, k;
	cin >> a >> b >> c >> d >> e;
	cout << "β������1,2,3,4��" << endl;
	list1.insertByTail(a);
	list1.insertByTail(b);
	list1.insertByTail(c);
	list1.insertByTail(d);
	cout << "ͷ������9��" << endl;
	list1.insertByHead(e);
	cout << "��һ�δ�ӡ��" << endl;
	list1.printList();
	cout << "1��λ��ǰ����8��" << endl;
	list1.insertByFrontPos(1, 8);
	cout << "4��λ�ú����0��" << endl;
	list1.insertByBehindPos(4, 0);
	cout << "Ԫ��4ǰ����8��" << endl;
	list1.insertByFrontPosElem(4, 8);
	cout << "Ԫ��2�����0��" << endl;
	list1.insertByBehindPosElem(2, 0);
	cout << "�ڶ��δ�ӡ��" << endl;
	list1.printList();
	cout << "��ת����" << endl;
	list1.reverseList();
	cout << "���Ĵδ�ӡ��" << endl;
	list1.printList();
	cout << "����" << endl;
	list1.sortList();
	cout << "����δ�ӡ��" << endl;
	list1.printList();
	cout << "ɾ��Ԫ��2��" << endl;
	list1.deleteByElem(2);
	cout << "�����δ�ӡ��" << endl;
	list1.printList();
}

int main()
{
	testByInt();
	//testByStudent();
	return 0;
}