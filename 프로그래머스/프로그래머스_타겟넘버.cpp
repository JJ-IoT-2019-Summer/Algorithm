#include <string>
#include <vector>
#include <queue>

using namespace std;

int cnt;

void dfs(vector<int> numbers, int target, int sum, int depth) {
	if (depth >= numbers.size()) { // ���ڸ� �� ���� ���ϴٰ� �迭�� ũ�⸸ŭ Ŀ����
		if (sum == target) // �迭�� ���� Ÿ�ٰ� ���ٸ� cnt ����
			cnt++;
		return;              // dfs ����
	}
	dfs(numbers, target, sum + numbers[depth], depth + 1); // ���� ���ڸ� ����
	dfs(numbers, target, sum - numbers[depth], depth + 1); // ���� ���ڸ� ��
}

int solution(vector<int> numbers, int target) {
	
	dfs(numbers, target, numbers[0], 1); // ù�� ° ���ڸ� ���� ���
	dfs(numbers, target, numbers[0] * -1, 1); //�ι� °  ���ڸ� �� ���

	return cnt;
}

