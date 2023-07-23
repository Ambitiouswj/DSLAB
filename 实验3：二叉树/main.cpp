#include "Tree.h"
#include "TreeNode.h"

void test_01()
{
	cout << "根据字符串生成二叉树" << endl;
	Tree<char> t1;
	char s[] = "A(B(D(,G),),C(E(H,J),F))";
	t1.createTree(s);
	cout << "节点个数：";
	cout << t1.getNumOfNode() << endl;
	cout << "前序遍历：";
	t1.preOrder(t1.getRoot());
	cout << endl << "中序遍历：";
	t1.inOrder(t1.getRoot());
	cout << endl << "后序遍历：";
	t1.postOrder(t1.getRoot());

	cout << endl << "前序遍历（非递归）：";
	t1.preOrderByStack();
	cout << "中序遍历（非递归）：";
	t1.inOrderByStack();
	cout << "后序遍历（非递归）：";
	t1.postOrderByStack();

	cout << "层序遍历：";
	t1.levelOrder();
	cout << "输出二叉树：";
	t1.dispTree(t1.getRoot());

	cout << endl << "翻转二叉树：";
	t1.invertTree(t1.getRoot());
	cout << endl;

	cout << "前序遍历：";
	t1.preOrder(t1.getRoot());
	cout << endl << "中序遍历：";
	t1.inOrder(t1.getRoot());
	cout << endl << "后序遍历：";
	t1.postOrder(t1.getRoot());

	cout << endl << "前序遍历（非递归）：";
	t1.preOrderByStack();
	cout << "中序遍历（非递归）：";
	t1.inOrderByStack();
	cout << "后序遍历（非递归）：";
	t1.postOrderByStack();

	cout << "层序遍历：";
	t1.levelOrder();
	cout << "输出二叉树：";
	t1.dispTree(t1.getRoot());

	cout << endl << "最大深度：";
	cout << t1.maxDepth(t1.getRoot()) << endl;
	cout << "最小深度：";
	cout << t1.minDepth(t1.getRoot()) << endl;
}

void test_02()
{
	cout << "根据前序遍历和中序遍历生成二叉树" << endl;
	char s1[] = "ABDGCEHJF";
	char s2[] = "DGBAHEJCF";
	Tree<char> t1;
	t1.createTreeByPreAndIn(s1, s2, 9);

	cout << "节点个数：";
	cout << t1.getNumOfNode() << endl;
	cout << "前序遍历：";
	t1.preOrder(t1.getRoot());
	cout << endl << "中序遍历：";
	t1.inOrder(t1.getRoot());
	cout << endl << "后序遍历：";
	t1.postOrder(t1.getRoot());

	cout << endl << "前序遍历（非递归）：";
	t1.preOrderByStack();
	cout << "中序遍历（非递归）：";
	t1.inOrderByStack();
	cout << "后序遍历（非递归）：";
	t1.postOrderByStack();

	cout << "层序遍历：";
	t1.levelOrder();
	cout << "输出二叉树：";
	t1.dispTree(t1.getRoot());

	cout << endl << "翻转二叉树：";
	t1.invertTree(t1.getRoot());
	cout << endl;

	cout << "前序遍历：";
	t1.preOrder(t1.getRoot());
	cout << endl << "中序遍历：";
	t1.inOrder(t1.getRoot());
	cout << endl << "后序遍历：";
	t1.postOrder(t1.getRoot());

	cout << endl << "前序遍历（非递归）：";
	t1.preOrderByStack();
	cout << "中序遍历（非递归）：";
	t1.inOrderByStack();
	cout << "后序遍历（非递归）：";
	t1.postOrderByStack();

	cout << "层序遍历：";
	t1.levelOrder();
	cout << "输出二叉树：";
	t1.dispTree(t1.getRoot());

	cout << endl << "最大深度：";
	cout << t1.maxDepth(t1.getRoot()) << endl;
	cout << "最小深度：";
	cout << t1.minDepth(t1.getRoot()) << endl;
}

void test_03()
{
	cout << "根据中序遍历和后序遍历生成二叉树" << endl;
	char s1[] = "GDBHJEFCA";
	char s2[] = "DGBAHEJCF";
	Tree<char> t1;
	t1.createTreeByInAndPost(s2, s1, 9);

	cout << "节点个数：";
	cout << t1.getNumOfNode() << endl;
	cout << "前序遍历：";
	t1.preOrder(t1.getRoot());
	cout << endl << "中序遍历：";
	t1.inOrder(t1.getRoot());
	cout << endl << "后序遍历：";
	t1.postOrder(t1.getRoot());

	cout << endl << "前序遍历（非递归）：";
	t1.preOrderByStack();
	cout << "中序遍历（非递归）：";
	t1.inOrderByStack();
	cout << "后序遍历（非递归）：";
	t1.postOrderByStack();

	cout << "层序遍历：";
	t1.levelOrder();
	cout << "输出二叉树：";
	t1.dispTree(t1.getRoot());

	cout << endl << "翻转二叉树：";
	t1.invertTree(t1.getRoot());
	cout << endl;

	cout << "前序遍历：";
	t1.preOrder(t1.getRoot());
	cout << endl << "中序遍历：";
	t1.inOrder(t1.getRoot());
	cout << endl << "后序遍历：";
	t1.postOrder(t1.getRoot());

	cout << endl << "前序遍历（非递归）：";
	t1.preOrderByStack();
	cout << "中序遍历（非递归）：";
	t1.inOrderByStack();
	cout << "后序遍历（非递归）：";
	t1.postOrderByStack();

	cout << "层序遍历：";
	t1.levelOrder();
	cout << "输出二叉树：";
	t1.dispTree(t1.getRoot());

	cout << endl << "最大深度：";
	cout << t1.maxDepth(t1.getRoot()) << endl;
	cout << "最小深度：";
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