#include "Tree.h"
#include "TreeNode.h"

void test_01()
{
	cout << "�����ַ������ɶ�����" << endl;
	Tree<char> t1;
	char s[] = "A(B(D(,G),),C(E(H,J),F))";
	t1.createTree(s);
	cout << "�ڵ������";
	cout << t1.getNumOfNode() << endl;
	cout << "ǰ�������";
	t1.preOrder(t1.getRoot());
	cout << endl << "���������";
	t1.inOrder(t1.getRoot());
	cout << endl << "���������";
	t1.postOrder(t1.getRoot());

	cout << endl << "ǰ��������ǵݹ飩��";
	t1.preOrderByStack();
	cout << "����������ǵݹ飩��";
	t1.inOrderByStack();
	cout << "����������ǵݹ飩��";
	t1.postOrderByStack();

	cout << "���������";
	t1.levelOrder();
	cout << "�����������";
	t1.dispTree(t1.getRoot());

	cout << endl << "��ת��������";
	t1.invertTree(t1.getRoot());
	cout << endl;

	cout << "ǰ�������";
	t1.preOrder(t1.getRoot());
	cout << endl << "���������";
	t1.inOrder(t1.getRoot());
	cout << endl << "���������";
	t1.postOrder(t1.getRoot());

	cout << endl << "ǰ��������ǵݹ飩��";
	t1.preOrderByStack();
	cout << "����������ǵݹ飩��";
	t1.inOrderByStack();
	cout << "����������ǵݹ飩��";
	t1.postOrderByStack();

	cout << "���������";
	t1.levelOrder();
	cout << "�����������";
	t1.dispTree(t1.getRoot());

	cout << endl << "�����ȣ�";
	cout << t1.maxDepth(t1.getRoot()) << endl;
	cout << "��С��ȣ�";
	cout << t1.minDepth(t1.getRoot()) << endl;
}

void test_02()
{
	cout << "����ǰ�����������������ɶ�����" << endl;
	char s1[] = "ABDGCEHJF";
	char s2[] = "DGBAHEJCF";
	Tree<char> t1;
	t1.createTreeByPreAndIn(s1, s2, 9);

	cout << "�ڵ������";
	cout << t1.getNumOfNode() << endl;
	cout << "ǰ�������";
	t1.preOrder(t1.getRoot());
	cout << endl << "���������";
	t1.inOrder(t1.getRoot());
	cout << endl << "���������";
	t1.postOrder(t1.getRoot());

	cout << endl << "ǰ��������ǵݹ飩��";
	t1.preOrderByStack();
	cout << "����������ǵݹ飩��";
	t1.inOrderByStack();
	cout << "����������ǵݹ飩��";
	t1.postOrderByStack();

	cout << "���������";
	t1.levelOrder();
	cout << "�����������";
	t1.dispTree(t1.getRoot());

	cout << endl << "��ת��������";
	t1.invertTree(t1.getRoot());
	cout << endl;

	cout << "ǰ�������";
	t1.preOrder(t1.getRoot());
	cout << endl << "���������";
	t1.inOrder(t1.getRoot());
	cout << endl << "���������";
	t1.postOrder(t1.getRoot());

	cout << endl << "ǰ��������ǵݹ飩��";
	t1.preOrderByStack();
	cout << "����������ǵݹ飩��";
	t1.inOrderByStack();
	cout << "����������ǵݹ飩��";
	t1.postOrderByStack();

	cout << "���������";
	t1.levelOrder();
	cout << "�����������";
	t1.dispTree(t1.getRoot());

	cout << endl << "�����ȣ�";
	cout << t1.maxDepth(t1.getRoot()) << endl;
	cout << "��С��ȣ�";
	cout << t1.minDepth(t1.getRoot()) << endl;
}

void test_03()
{
	cout << "������������ͺ���������ɶ�����" << endl;
	char s1[] = "GDBHJEFCA";
	char s2[] = "DGBAHEJCF";
	Tree<char> t1;
	t1.createTreeByInAndPost(s2, s1, 9);

	cout << "�ڵ������";
	cout << t1.getNumOfNode() << endl;
	cout << "ǰ�������";
	t1.preOrder(t1.getRoot());
	cout << endl << "���������";
	t1.inOrder(t1.getRoot());
	cout << endl << "���������";
	t1.postOrder(t1.getRoot());

	cout << endl << "ǰ��������ǵݹ飩��";
	t1.preOrderByStack();
	cout << "����������ǵݹ飩��";
	t1.inOrderByStack();
	cout << "����������ǵݹ飩��";
	t1.postOrderByStack();

	cout << "���������";
	t1.levelOrder();
	cout << "�����������";
	t1.dispTree(t1.getRoot());

	cout << endl << "��ת��������";
	t1.invertTree(t1.getRoot());
	cout << endl;

	cout << "ǰ�������";
	t1.preOrder(t1.getRoot());
	cout << endl << "���������";
	t1.inOrder(t1.getRoot());
	cout << endl << "���������";
	t1.postOrder(t1.getRoot());

	cout << endl << "ǰ��������ǵݹ飩��";
	t1.preOrderByStack();
	cout << "����������ǵݹ飩��";
	t1.inOrderByStack();
	cout << "����������ǵݹ飩��";
	t1.postOrderByStack();

	cout << "���������";
	t1.levelOrder();
	cout << "�����������";
	t1.dispTree(t1.getRoot());

	cout << endl << "�����ȣ�";
	cout << t1.maxDepth(t1.getRoot()) << endl;
	cout << "��С��ȣ�";
	cout << t1.minDepth(t1.getRoot()) << endl;
}

int main()
{
	test_01();
	cout << endl << endl << endl << endl;
	test_02();
	cout << endl << endl << endl << endl;
	test_03();
	cout << endl << endl << endl << endl;
	return 0;
}