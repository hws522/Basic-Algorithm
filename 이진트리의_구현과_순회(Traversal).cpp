/*
가장 많이 사용되는 비선형 자료구조는 이진트리.
이진트리는 데이터의 탐색 속도 증진을 이해 사용하는 구조.
포인터를 사용해야함.
완전이진트리는 배열로 표현가능하지만, 다른 이진트리는 배열로 
표현하기 어렵기 때문.(데이터의 낭비를 줄일 수 있음)
이진트리에서 데이터를 탐색하는방법은 전위순회, 중위순회, 후위순회가 있음.
수식기반형식은 후위순회방식이 사용됨. 
*/

#include<iostream>

using namespace std;

const int number = 15;

//하나의 노드 정보를 선언. 
typedef struct node *treePointer;
typedef struct node
{
	int data;
	treePointer leftChild, rightChild;

} node;

//전위 순회.
void preorder(treePointer ptr)
{
	if (ptr)//null 이 아닐때
	{
		cout << ptr->data << ' ';
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}

//중위 순회.
void inorder(treePointer ptr)
{
	if (ptr)//null 이 아닐때
	{
		inorder(ptr->leftChild);
		cout << ptr->data << ' ';
		inorder(ptr->rightChild);
	}
}

//후위 순회.
void postorder(treePointer ptr)
{
	if (ptr)//null 이 아닐때
	{
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		cout << ptr->data << ' ';
	}
}

int main()
{
	node nodes[number + 1]; //1번노드부터 넣기위해 +1.

	for (int i = 1; i <= number; i++)
	{
		nodes[i].data = i;
		nodes[i].leftChild = NULL;
		nodes[i].rightChild = NULL;
	}

	for (int i = 1; i <= number; i++)
	{
		if (i % 2 == 0)
		{
			nodes[i / 2].leftChild = &nodes[i];
		}

		else
		{
			nodes[i / 2].rightChild = &nodes[i];
		}
	}

	preorder(&nodes[1]);
	cout << endl;
	inorder(&nodes[1]);
	cout << endl;
	postorder(&nodes[1]);
	cout << endl;

	return 0;
}

