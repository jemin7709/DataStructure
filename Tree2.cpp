#include <iostream>
#include <vector>

using namespace std;

struct TreeData
{
	int height;
	int length;
	int** arr;
};

class Node {
public:
	int data;
	Node* par;
	vector<Node*> chi_v;

	Node(int data)
	{
		this->data = data;
		this->par = NULL;
	}
};

class Tree {
public:
	Node* root;
	vector<Node*> node_v;

	Tree(int);
	void insertNode(int, int);
	void delNode(int);
	void preorder(Node*);
	void postorder(Node*);
};

Tree::Tree(int data)
{
	Node* node = new Node(data);
	this->root = node;
	this->node_v.push_back(node);
}

void Tree::insertNode(int par_data, int data)
{
	Node* node = new Node(data);

	for (int i = 0; i < node_v.size(); i++)
	{
		if (node_v[i]->data == par_data)
		{
			node_v[i]->chi_v.push_back(node);
			node_v.push_back(node);
			node->par = node_v[i];
			return;
		}
	}

	cout << -1 << endl;
}

void Tree::delNode(int data)
{
	Node* curNode;
	Node* parNode;

	for (int i = 0; i < node_v.size(); i++)
	{
		if (node_v[i]->data == data)
		{
			if (node_v[i] == root)
			{
				cout << -1 << endl;
				return;
			}

			curNode = node_v[i];
			parNode = curNode->par;
			for (Node* child : curNode->chi_v)
			{
				parNode->chi_v.push_back(child);
				child->par = parNode;
			}

			for (int j = 0; j < parNode->chi_v.size(); j++)
			{
				if (parNode->chi_v[j]->data == data)
				{
					parNode->chi_v.erase(parNode->chi_v.begin() + j);
				}
			}

			node_v.erase(node_v.begin() + i);
			delete curNode;
			return;
		}
	}

	cout << -1 << endl;
}

void Tree::preorder(Node* node)
{
	if (!node) return;

	cout << node->data << " ";

	for (int i = 0; i < node->chi_v.size(); i++)
	{
		preorder(node->chi_v[i]);
	}

}

void Tree::postorder(Node* node)
{
	if (!node) return;

	for (int i = 0; i < node->chi_v.size(); i++)
	{
		postorder(node->chi_v[i]);
	}

	if (node == root)
		cout << 0 << " ";
	else
		cout << node->par->data << " ";
}

TreeData getReach(int* depth, int* data)	// ���߹迭�� ���� Ʈ���� ����ȭ�Ͽ� ��ȯ
{
	int height = 0, length = 0, n = 0;
	int idx = 0;

	while (depth[idx] != 0)			// Ʈ���� depth ����
	{
		if (depth[idx] > height)
			height = depth[idx];
		++idx;
	}
	n = idx + 1;

	int* temp1 = new int[height + 1];
	memset(temp1, 0, sizeof(int) * (height + 1));
	idx = 0;
	while (depth[idx] != 0)			// �� depth�� �ش��ϴ� ����� ���� -> ���� ū ���� length,,
	{
		++temp1[depth[idx]];
		++idx;
	}

	for (int i = 0; i < height + 1; i++)	// ���� ū length�� ���� ��ŭ �Ҵ����ش�.
	{
		if (temp1[i] > length)
			length = temp1[i];
	}

	int** arrReturn = new int* [height + 1];

	for (int i = 0; i < height + 1; i++)
	{
		arrReturn[i] = new int[2 * length];		// 2* length -> ¦�������� data�� �ְ� Ȧ�������� �ڽĳ���� ���� ����.
		memset(arrReturn[i], 0, 2 * length * sizeof(int));
	}

	// �ʱ� �� ���õ� ���߹迭 �ϼ�. ���� �� ���� �־������.

	for (int i = 0; i < height + 1; i++)
	{
		int cur = 0;							// Ŀ��
		int temp = 0;							// ��� ���� ī��Ʈ ���� ����
		idx = 0;
		for (int j = 0; j < n; j++)
		{
			if (depth[j] == i)
			{
				arrReturn[i][cur * 2] = data[j];

				if (i == height)					// �ݵ�� leaf��忡 �ش��ϹǷ� �ڼ��� �������� ����.
				{
					arrReturn[i][cur * 2 + 1] = 0;	// ��, �ڼ� ������ ���� 0��
				}
				else
				{
					for (idx = temp; idx < j; idx++)
					{
						if (depth[idx] == i + 1)
							++arrReturn[i][cur * 2 + 1];
					}
				}

				temp = j;
				cur++;
			}
		}
	}

	delete[] temp1;

	return { height + 1, length, arrReturn };
}

int main()
{
	int T, N, var1, var2;
	int* arrTree, * arrDepth; 	// Ʈ���� ����Ʈ�� ������ �ɰ��� ������ �迭
	TreeData td = { 0 };
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		Tree tr(1);

		cin >> N;

		arrTree = new int[N]();
		arrDepth = new int[N]();
		memset(arrTree, 0, N * sizeof(int));
		memset(arrDepth, 0, N * sizeof(int));

		for (int j = 0; j < N; j++)
		{
			cin >> var1;
			arrTree[j] = var1;
		}

		for (int j = 0; j < N; j++)
		{
			cin >> var1;
			arrDepth[j] = var1;
		}

		td = getReach(arrDepth, arrTree);

		/*
		cout << endl;

		for (int j = 0; j < td.height; j++)
		{
			for (int k = 0; k < td.length; k++)
			{
				cout << td.arr[j][2 * k] << " " << td.arr[j][2 * k + 1] << "	";
			}
			cout << endl << endl;
		}
		*/

		for (int j = 1; j < td.height; j++)
		{
			int cur = 0;
			int curTemp = 0;
			int k = 0;

			while (td.arr[j][2 * k] != 0 && k != td.length)
			{
				if (curTemp == td.arr[j - 1][2 * cur + 1] ||
					td.arr[j - 1][2 * cur + 1] == 0)
				{
					cur++;
					curTemp = 0;
				}
				else
				{
					tr.insertNode(td.arr[j - 1][cur * 2], td.arr[j][k * 2]);
					curTemp++;
					++k;
				}
				//cout << "insert " << td.arr[j][k * 2] << " in " << td.arr[j - 1][cur * 2] << endl;
		// �̰� �ּ� �����Ͻø� �ڵ� ��� ���ư����� �� ���̽ǰſ���!
			}
		}


		delete[] arrTree;
		delete[] arrDepth;
		for (int j = 0; j < td.height; j++)
			delete[] td.arr[j];
		delete[] td.arr;


		tr.preorder(tr.root);

		cout << endl;

	}

	return 0;
}
