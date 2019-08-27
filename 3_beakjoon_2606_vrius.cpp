#include<iostream>
#include <vector>
#include <cstring>
#include<stack>
using namespace std;

vector <int> ad[101];
bool visit[101];
int C;	//���̷����� ������ ��ǻ�� �� 
int N, P;
// N�� ��ǻ���� �� , P �� ��Ʈ��ũ �󿡼� ��������Ǿ� �ִ� ��ǻ�� ���� �� 

void DFS()
{
	int V = 1;
	C = 0;
	memset(visit, false, sizeof(visit));	// �湮 �迭 �ʱ�ȭ
	stack<int> s;
	s.push(V);

	while (!s.empty())
	{
		V = s.top();
		s.pop();
		if (!visit[V])	//���� �湮 ���� Ȯ��
		{
			C++;
			visit[V] = true;
		}
		for (int i = 0;i < ad[V].size();i++)	//�ֺ� ��� �湮 ���� Ȯ�� 
		{
			if (!visit[ad[V].at(i)])
				s.push(ad[V].at(i));
		}
	}
}


int main()
{
	
	cin >> N >> P;
	int start, end;

	for (int i = 1; i <= P; i++) // ����� ����ŭ �ݺ��� 
	{
		cin >> start >> end;
		ad[start].push_back(end);
		ad[end].push_back(start);
	}
	DFS();
	cout << C-1 << endl;



}