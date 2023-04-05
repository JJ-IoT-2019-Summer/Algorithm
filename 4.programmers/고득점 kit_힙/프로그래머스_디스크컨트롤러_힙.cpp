
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int>a, pair<int, int>b) {
	if (a.first == b.first) return a.second < b.second;
	//�۾� �ҿ�ð��� ���ٸ� ���� ��û�Ȱͺ���
	else return a.first < b.first;
	//�۾� �ҿ�ð��� ���� ��������
}

// ������ �����ʺ��� ���� �� �ֵ��� ���� 
int solution(vector<vector<int>> jobs) { //�۾��� ��û�Ǵ� ����,�ҿ�Ǵ� �ð�

	int nsize = jobs.size(); // ��� �۾��� ��û�Ǿ�����
	int workTime = 0;

	vector<pair<int, int>> v; //�۾��� �ҿ�Ǵ½ð�, �۾��� ��û�Ǵ� ����

	for (int i = 0; i < nsize; ++i)
		v.push_back({ jobs[i][1],jobs[i][0] });

	sort(v.begin(), v.end(), cmp);

	int cur_time = 0, total_time = 0;

	while (!v.size() == 0) { // �۾���û�� �����ϸ�
		for (int i = 0; i < v.size(); ++i) { // �۾���û���� Ȯ��
			if (cur_time >= v[i].second) { //���� �ð��� �۾���û�ð��� ���ų� �������
				cur_time += v[i].first;			// �۾� �ҿ�ð� �߰�
				total_time = total_time + cur_time - v[i].second;
									// �۾��� ��û�Ƚ����� �������
				v.erase(v.begin() + i); //�ش��û�� ����Ǿ����Ƿ� ����
				break;
			}
			if (i == v.size() - 1) cur_time++;
									//���� �۾��� ������ ���� �����۾����� ������ ���� ���
		}
	}

	return total_time / nsize;
}

int main()
{
	vector<vector<int>> jobs = { {0,3},{1,9},{2,6} };
	cout << solution(jobs);
	return 0;
}