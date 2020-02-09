/*
Ư���� ���ڿ� ��Ī �˰���.
�׻� �������� ������, �Ϲ����ΰ�� ������ �۵��ϴ� ������ ������ ���ڿ� ��Ī �˰���.
�ؽ�(Hash) ����� ���. 
Hash�� �� �����͸� �װ��� ��¡�ϴ� ª�� �����ͷ� �ٲپ��ִ� ���.
���� ���ڿ� ��Ī�� �������� ���ڿ��� �̾����� ��쿡 ����ϱ� ������ 
Hash���� �������� ��쿡 �� ������ ���� �� �ִ� �˰����� ä���Ͽ� �����Ѵٸ� ������ ���� ����.

�ؽ��Լ��� �� ������ �ƽ�Ű�ڵ� ���� 2�� ���� ���� ���ʷ� ���Ͽ� ������ ��.
���ڿ��� �޶����� ����� ��µǴ� �ؽ� ���� �ٲ�.
�ؽ� ���� �ߺ��Ǿ� �浹�� �Ͼ�� ��쵵 ������, �߻����� ���� �ʾ� ����.
�浹�� �Ͼ ��� �����͸� �̿��� ���� �ڷᱸ���� �ذ�.

��, ��� ī�� �˰����� ���� ���� ���ڿ��� ���� �� �׻� �ؽ� ���� ���Ͽ� ���ϰ�,
�ؽ� ���� ���� ��ġ �ϴ� ���� ���� ������ �� �۰� �κ� ���ڿ��� �ؽ� ���� ��ġ�ϴ� ��쿡�� 
���ڿ��� ��˻��Ͽ� ��Ȯ�� ��ġ �ϴ��� Ȯ�� �ϴ� �˰���.

��� ī�� �˰����� �ð����⵵�� O(N).
*/

#include<iostream>

using namespace std;

void findString(string parent, string pattern)
{
	int parentSize = parent.size();
	int patternSize = pattern.size();
	int parentHash = 0;
	int patternHash = 0;
	int power = 1; //�������� �ǹ�.

	for (int i = 0; i <= parentSize - patternSize; i++)
	{
		if (i == 0)
		{
			for (int j = 0; j < patternSize; j++) //�⺻ �ؽð��� ����.
			{
				parentHash += parent[patternSize - 1 - j] * power;
				patternHash += pattern[patternSize - 1 - j] * power;

				if (j < patternSize - 1)
					power = power * 2;
			}
		}

		else
		{
			parentHash = 2 * (parentHash - parent[i - 1] * power) +
							parent[patternSize - 1 + i];
		}

		if (parentHash == patternHash) //�ؽð��� ���� ��� ��� ���ڿ� ��.
		{
			bool finded = true;

			for (int j = 0; j < patternSize; j++)
			{
				if (parent[i + j] != pattern[j])
				{
					finded = false;
					break;
				}
			}
			if (finded)
			{
				cout << i + 1 << "��°���� �߰��߽��ϴ�. " << endl;
			}
		}
	}
}

int main()
{
	string parent = "ababacabacaabacaaba";
	string pattern = "abacaaba";

	findString(parent, pattern);

	return 0;
}