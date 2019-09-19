#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int solution(vector<int> budgets, int M) {

	sort(budgets.begin(), budgets.end()); //�Լ����� 

	int low = 0;
	int high = *max_element(budgets.begin(), budgets.end()); // ���� �� ���� ū ��

	long sum = 0;
	int answer = 0;
	int mid = 0;

	while (low <= high) {
		mid = (low + high) / 2;
		sum = 0;

		for (int i : budgets) {
			if (mid > i) sum += i;  // ��û�� ������ ������ �߰� ������ ���� �� 
			else sum += mid;    // ��û�� ������ ������ �߰� ������ Ŭ ��, mid �� ���� 
		}
		if (sum > M) {              //������ ������ �Է��� ���� ���� ũ��
			high = mid - 1;     // high ���̱�
		}
		else {
			answer = mid;       //������ ������ �Է��� ���� ���� ������ ������ �� �ִ��� �� �������� �����ټ�����
								// ���� mid �� answer�� �ֱ�
			low = mid + 1;        // low �ø���
		}

	}
	return answer;
}