#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	queue<pair<int, int>> q;
	priority_queue<int>pq;

	for (int i = 0; i < priorities.size(); i++) {
		q.push(pair<int, int>(i, priorities[i]));
		pq.push(priorities[i]); //�����Ͽ� ť�� �Է�
	}

	while (!q.empty()) {
		pair<int, int> current = q.front(); // ������� ���� �տ� ������ ������

		if (current.second == pq.top()) // �߿䵵�� ���� Ŭ ���
		{
			if (current.first == location) { // �߿伺 ���� ���� ���� �˰� ���� ��
				return answer + 1;
			}
			else { // �߿伺 ���� �� �� ���� �˰� ���� ���� �ƴ� ���       
				q.pop(); // �߿伺 ū �� ���� �ϳ��� �����
				pq.pop();
				answer++; //��ġ ��ġ �̵�
			}
		}
		else {   // ����Ͽ��� �߿䵵�� ���� ������ �Ѱ��� ����
			q.push(current); // �� �ڷ� �̵�
 			q.pop(); // �� ���� �۾� ����
		}

	}
	return answer;

}