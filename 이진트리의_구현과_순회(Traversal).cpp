/*
���� ���� ���Ǵ� ���� �ڷᱸ���� ����Ʈ��.
����Ʈ���� �������� Ž�� �ӵ� ������ ���� ����ϴ� ����.
�����͸� ����ؾ���.
��������Ʈ���� �迭�� ǥ������������, �ٸ� ����Ʈ���� �迭�� 
ǥ���ϱ� ��Ʊ� ����.(�������� ���� ���� �� ����)
����Ʈ������ �����͸� Ž���ϴ¹���� ������ȸ, ������ȸ, ������ȸ�� ����.
���ı�������� ������ȸ����� ����. 
*/

#include<iostream>

using namespace std;

const int number = 15;

//�ϳ��� ��� ������ ����. 
typedef struct node *treePointer;
typedef struct node
{
	int data;
	treePointer leftChild, rightChild;

} node;

//���� ��ȸ.
void preorder(treePointer ptr)
{
	if (ptr)//null �� �ƴҶ�
	{
		cout << ptr->data << ' ';
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}

//���� ��ȸ.
void inorder(treePointer ptr)
{
	if (ptr)//null �� �ƴҶ�
	{
		inorder(ptr->leftChild);
		cout << ptr->data << ' ';
		inorder(ptr->rightChild);
	}
}

//���� ��ȸ.
void postorder(treePointer ptr)
{
	if (ptr)//null �� �ƴҶ�
	{
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		cout << ptr->data << ' ';
	}
}

int main()
{
	node nodes[number + 1]; //1�������� �ֱ����� +1.

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

