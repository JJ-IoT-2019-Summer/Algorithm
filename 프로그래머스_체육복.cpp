#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	int num_lost = lost.size();

	for (int i = 0; i < lost.size(); i++) {
		for (int j = 0; j < reserve.size(); j++) {
			if (lost[i] == reserve[j]) { // ü������ ������ �� ������ ������ ���� �� ����.
				lost.erase(lost.begin() + i);  //ü������ ���� �ʿ䰡 ����
				reserve.erase(reserve.begin() + j); // ������ ���� ������ reserv���� ����
				i--;
				j--;        //ũ�Ⱑ �ϳ��� ����
				num_lost--; // �Ҿ���� ����� ���� 1�� �پ���
			}
		}
	}

	for (int i = 0; i < lost.size(); i++) {
		for (int j = 0; j < reserve.size(); j++) {
			if (lost[i] - 1 == reserve[j] || lost[i] + 1 == reserve[j]) { // �ֺ��� ������ �ִ� �л��� ����
				reserve.erase(reserve.begin() + j);  // ������ ���� ��� ������ reserve���� ����
				num_lost--;                           // �Ҿ���� ����� ���� 1�� �پ���
				break;
			}
		}
	}
	return n - num_lost;
}