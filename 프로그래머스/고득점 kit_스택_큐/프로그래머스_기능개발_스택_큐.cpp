#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	vector<int> q = progresses;
	vector<int> sq = speeds;

	while (!q.empty()) {
		int front = q[0];
		int qsize = q.size();

		if (front == 100) { // ���� �����Ǿ�� �ϴ� ���� ������ �� �Ǿ�����
			int cnt = 0;
			for (int i = 0; i < qsize; ) {
				if (q.empty() || q[i] != 100)  { // ��� �����Ǿ��ų� ���������� ���� ������
					answer.emplace_back(cnt); // ������ ��� �� �߰� 
					break;
				}
	
				q.erase(q.begin()+i); // ������� �������̸� ť���� ����
  				sq.erase(sq.begin()+i);
				cnt++; // ���������� ��� �����Ǵ��� üũ
			}
		}
		else { // ���� �����Ǿ�� �ϴ� ���� ������ ���� �ʾ�����
			for (int i = 0; i < qsize; ++i) {
				q[i] += sq[i];
				if (q[i] > 100) q[i] = 100;
			}
		}
	}

	return answer;
}

int main()
{

	vector<int> prog ({ 93,30,55 });
	vector<int> speed({ 1,30,5 });

	vector<int> result = solution(prog, speed);
	for (int i = 0; i < result.size(); ++i) {
		cout << result[i] << " ";
	}
	return 0;
}