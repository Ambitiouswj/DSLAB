#include "Head.h"
#include "student.h"

void testByClass() 
{
    SqList<Student> list2(20);
    list2.pushBack(Student("李四", "63210506", 97, 87, 60));
    list2.pushBack(Student("张三", "63210501", 93, 65, 86));
    list2.pushBack(Student("王五", "63210509", 90, 20, 53));
    list2.pushBack(Student("赵四", "63210505", 91, 66, 81));
    Student s1("测试", "12123", 65, 98, 64);
    Student s2("李四", "63210506", 97, 87, 60);
    Student s3("赵四", "63210505", 91, 66, 81);
    cout << "添加Student测试" << endl;
    list2.printList();
    cout << "李四后插入Student测试" << endl;
    list2.insertByBehindElem(s2, s1);
    list2.printList();
    cout << "赵四前插入Student测试" << endl;
    list2.insertByFrontElem(s3, s1);
    list2.printList();
    cout << "排序测试" << endl;
    list2.sortList(1, list2.lengthOfList());
    list2.printList();
    cout << "删除测试" << endl;
    list2.deleteByElem(s1);
    list2.printList();
}

void testByInt()
{
    SqList<int> list1(1000);
    cout << "尾部插入 | 1，3，5" << endl;
    list1.pushBack(1);
    list1.pushBack(3);
    list1.pushBack(5);
    cout << "指定元素前插入 | 5前面插入0" << endl;
    list1.insertByFrontElem(0, 5);
    cout << "指定元素后插入 | 3后面插入4" << endl;
    list1.insertByBehindElem(4, 3);
    cout << "第一次打印" << endl;
    list1.printList();
    cout << "升序排序" << endl;
    list1.sortList(1, list1.lengthOfList());
    cout << "第二次打印" << endl;
    list1.printList();
    cout << "删除2号位置元素" << endl;
    list1.deleteByPos(2);
    cout << "删除元素：5" << endl;
    list1.deleteByElem(5);
    cout << "第三次打印" << endl;
    list1.printList();
    int x;
    cout << "提取2号位置元素" << endl;
    list1.searchByPos(2, x);
    cout << x << endl;
    cout << "查找元素0的位置" << endl;
    list1.searchByElem(x, 0);
    cout << x << endl;
    cout << "将3号位置的元素改为9" << endl;
    list1.alter(3, 9);
    list1.printList();
}

void testByFile()
{
    ifstream ifs("测试.in");
    ofstream cout("测试.out");
    SqList<int> list1(1000);
    cout << "尾部插入 | 1，3，5" << endl;
    int a, b, c, d, e, f;
    ifs >> a >> b >> c >> d >> e >> f;
    list1.pushBack(a);
    list1.pushBack(b);
    list1.pushBack(c);
    cout << "指定元素前插入 | 5前面插入0" << endl;
    list1.insertByFrontElem(0, d);
    cout << "指定元素后插入 | 3后面插入4" << endl;
    list1.insertByBehindElem(4, e);
    cout << "第一次打印" << endl;
    list1.printList();
    cout << "升序排序" << endl;
    list1.sortList(1, list1.lengthOfList());
    cout << "第二次打印" << endl;
    list1.printList();
    cout << "删除2号位置元素" << endl;
    list1.deleteByPos(2);
    cout << "删除元素：5" << endl;
    list1.deleteByElem(5);
    cout << "第三次打印" << endl;
    list1.printList();
    int x;
    cout << "提取2号位置元素" << endl;
    list1.searchByPos(2, x);
    cout << x << endl;
    cout << "查找元素0的位置" << endl;
    list1.searchByElem(x, 0);
    cout << x << endl;
    cout << "将3号位置的元素改为9" << endl;
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
