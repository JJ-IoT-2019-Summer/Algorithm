#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	priority_queue<int> pq;
	int lastDate = 0;

	while (stock < k) {      //st�� k���� ���ų� Ŀ���� ������ ���� ���� ( st�� �Ϸ縶�� -1 )
		while (lastDate < dates.size() && dates[lastDate] <= stock)
			// lastDate�� date�� ������ ���� �۰� (�ε��� ����)
			// �߰��Ϸ��� �� ���� stock�� ������ ( ��ƿ �� ������)  
			pq.push(supplies[lastDate++]); // �ִ� ���޷��� ť�� �ְ� +1����

		stock += pq.top(); // ���� ���� ���޷��� ������ �߰�
		pq.pop();
		answer++;       // �ؿ� ���忡�� ���� Ƚ�� ���� 
	}

	return answer;
}