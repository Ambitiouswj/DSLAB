#include "test_05.h"
#include "sort_test.h"

int a[10000];
int p[100000];

void testBinary()
{
	ifstream cin("D:\\10101数据结构A\\实验05\\text_1.txt");
	for (int i = 0; i < 10000; i++)
	{
		cin >> a[i];
	}
	cout << sizeof(a) << endl;
	SQList list1(a,10000);
	//list1.print();
	list1.quick_sort(0, list1.getNum() - 1);
	//list1.print();
	int cnt = 0;
	long long sum = 0;
	for (int i = 1; i <= 10000; i++)
	{
		list1.find(i, cnt);
		sum += cnt;
	}
	cout << "顺序表二分查找平均查找长度：";
	cout << sum / 10000.0 << endl;
}

void testBSTree()
{
	ifstream cin("D:\\10101数据结构A\\实验05\\text_1.txt");
	for (int i = 0; i < 10000; i++)
	{
		cin >> a[i];
	}
	/*int s[] = { 4,2,6,1,3,5,7 };
	Tree tr1(s, 7);
	tr1.preOrder(tr1.getRoot());
	cout << endl;
	tr1.inOrder(tr1.getRoot());
	cout << endl;
	tr1.postOrder(tr1.getRoot());
	cout << endl;
	tr1.levelOrder();
	cout << endl;
	cout << tr1.getNumOfNode() << endl;*/
	Tree tr1(a, 10000);
	int cnt = 0;
	long long sum = 0;
	for (int i = 1; i <= 10000; i++)
	{
		tr1.find(tr1.getRoot(), i, cnt);
		sum += cnt;
	}
	cout << "二叉搜索树平均查找长度：";
	cout << sum / 10000.0 << endl;
}

void testSort_1()
{
	ifstream cin("D:\\10101数据结构A\\实验05\\text_2.txt");
	for (int i = 0; i < 100000; i++)
	{
		cin >> p[i];
	}

	time_t time, start, end;//程序运行总时间、程序运行开始时刻、结束时刻
	start = clock();    //取得系统当前时刻
	insert_sort(p, 100000);
	
	end = clock();        //取得系统当前时刻
	time = end - start;
	cout << "插入排序耗时：" << time << " ms" << endl;

}

void testSort_2()
{
	ifstream cin("D:\\10101数据结构A\\实验05\\text_2.txt");
	for (int i = 0; i < 100000; i++)
	{
		cin >> p[i];
	}

	time_t time, start, end;//程序运行总时间、程序运行开始时刻、结束时刻
	start = clock();    //取得系统当前时刻

	bubble_sort(p, 100000);
	

	end = clock();        //取得系统当前时刻
	time = end - start;
	cout << "冒泡排序耗时：" << time << " ms" << endl;

}

void testSort_3()
{
	ifstream cin("D:\\10101数据结构A\\实验05\\text_2.txt");
	for (int i = 0; i < 100000; i++)
	{
		cin >> p[i];
	}

	time_t time, start, end;//程序运行总时间、程序运行开始时刻、结束时刻
	start = clock();    //取得系统当前时刻

	quick_sort(p, 0, 100000 - 1);

	end = clock();        //取得系统当前时刻
	time = end - start;
	cout << "快速排序耗时：" << time << " ms" << endl;

}

void testSort_4()
{
	ifstream cin("D:\\10101数据结构A\\实验05\\text_2.txt");
	for (int i = 0; i < 100000; i++)
	{
		cin >> p[i];
	}

	time_t time, start, end;//程序运行总时间、程序运行开始时刻、结束时刻
	start = clock();    //取得系统当前时刻
	
	merge_sort(p, 0, 100000 - 1);

	end = clock();        //取得系统当前时刻
	time = end - start;
	cout << "归并排序耗时：" << time << " ms" << endl;

}

signed main()
{
	//int a[] = {4, 2, 6, 1, 3, 5, 7};
	/*Tree tr1(a);
	tr1.preOrder(tr1.getRoot());
	cout << endl;
	tr1.inOrder(tr1.getRoot());
	cout << endl;
	tr1.postOrder(tr1.getRoot());
	cout << endl;
	tr1.levelOrder();
	cout << endl;
	cout << tr1.getNumOfNode() << endl;*/
	//testBinary();
	//testBSTree();

	testSort_1();
	testSort_2();
	testSort_3();
	testSort_4();
	return 0;
}