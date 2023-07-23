#include "List.h"
#include "ListNode.h"
#include "student.h"

void testByInt()
{
	List<int> list1;
	cout << "尾部插入1,2,3,4：" << endl;
	list1.insertByTail(1);
	list1.insertByTail(2);
	list1.insertByTail(3);
	list1.insertByTail(4);
	cout << "头部插入9：" << endl;
	list1.insertByHead(9);
	cout << "第一次打印：" << endl;
	list1.printList();
	cout << "1号位置前插入8：" << endl;
	list1.insertByFrontPos(1, 8);
	cout << "4号位置后插入0：" << endl;
	list1.insertByBehindPos(4, 0);
	cout << "元素4前插入8：" << endl;
	list1.insertByFrontPosElem(4, 8);
	cout << "元素2后插入0：" << endl;
	list1.insertByBehindPosElem(2, 0);
	cout << "第二次打印：" << endl;
	list1.printList();
	cout << "反转链表：" << endl;
	list1.reverseList();
	cout << "第四次打印：" << endl;
	list1.printList();
	cout << "排序：" << endl;
	list1.sortList();
	cout << "第五次打印：" << endl;
	list1.printList();
	cout << "删除元素2：" << endl;
	list1.deleteByElem(2);
	cout << "第六次打印：" << endl;
	list1.printList();
}

void testByStudent()
{
	List<Student> list2;
	list2.insertByTail(Student("李四", "63210506", 97, 87, 60));
	list2.insertByTail(Student("张三", "63210501", 93, 65, 86));
	list2.insertByTail(Student("王五", "63210509", 90, 20, 53));
	list2.insertByHead(Student("赵四", "63210505", 91, 66, 81));
	Student s1("测试", "12120003", 65, 98, 64);
	Student s2("李四", "63210506", 97, 87, 60);
	Student s3("赵六", "63210505", 91, 66, 81);
	cout << "添加Student测试" << endl;
	list2.printList();
	cout << "李四后插入Student测试" << endl;
	list2.insertByBehindPosElem(s2, s1);
	list2.printList();
	cout << "赵四前插入Student测试" << endl;
	list2.insertByFrontPosElem(s3, s1);
	list2.printList();
	cout << "排序测试" << endl;
	list2.sortList();
	list2.printList();
	cout << "反转测试" << endl;
	list2.reverseList();
	list2.printList();
	cout << "删除测试" << endl;
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
	cout << "尾部插入1,2,3,4：" << endl;
	list1.insertByTail(a);
	list1.insertByTail(b);
	list1.insertByTail(c);
	list1.insertByTail(d);
	cout << "头部插入9：" << endl;
	list1.insertByHead(e);
	cout << "第一次打印：" << endl;
	list1.printList();
	cout << "1号位置前插入8：" << endl;
	list1.insertByFrontPos(1, 8);
	cout << "4号位置后插入0：" << endl;
	list1.insertByBehindPos(4, 0);
	cout << "元素4前插入8：" << endl;
	list1.insertByFrontPosElem(4, 8);
	cout << "元素2后插入0：" << endl;
	list1.insertByBehindPosElem(2, 0);
	cout << "第二次打印：" << endl;
	list1.printList();
	cout << "反转链表：" << endl;
	list1.reverseList();
	cout << "第四次打印：" << endl;
	list1.printList();
	cout << "排序：" << endl;
	list1.sortList();
	cout << "第五次打印：" << endl;
	list1.printList();
	cout << "删除元素2：" << endl;
	list1.deleteByElem(2);
	cout << "第六次打印：" << endl;
	list1.printList();
}

int main()
{
	testByInt();
	//testByStudent();
	return 0;
}