#include <string>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	vector<list<int>> graph(n + 1, list<int>()); //graph �׸��� ���� ���
	vector<int> dist(n + 1, 0); //1���� ���� �ش� ������ �Ÿ��� ��� ���� ��� 
								//ũ�� n+1, 0 ���� �ʱ�ȭ
	vector<bool> visit(n + 1, false);  // ��� �湮 ���� üũ 
	queue<int> q;	//��� ��ȣ �Է� 

	for (auto it = edge.begin(); it != edge.end(); it++) {
		graph[(*it).front()].push_back((*it).back());   //at() , [] �� ���� 
		graph[(*it).back()].push_back((*it).front());
	}

	q.push(1);
	visit[1] = true;	//��� 1���� Ȯ�� 
	dist[1] = 0;

	while (!q.empty()) {
		int current = q.front();   // ���� Ȯ���Ϸ��� ��� ��ȣ
		q.pop();

		for (auto i : graph[current]) {
			if (visit[i] == false) {   // �׷������� ����� ��� i Ȯ��
				visit[i] = true; //�湮������ ������ �湮���� �ٲٰ�
				q.push(i);		// ��� �湮 �ϱ� ���� queue�� ����
				dist[i] = dist[current] + 1;	//current ��忡�� +1 �Ÿ� ����
			}
		}
	}

	int max = *max_element(dist.begin(), dist.end()); // ���� �ָ� �ִ� ��� ��

	for (auto i : dist) {	// ���� �ָ� �ִ� ����� �� Ȯ��
		if (i == max) answer++;
	}

	return answer;
}