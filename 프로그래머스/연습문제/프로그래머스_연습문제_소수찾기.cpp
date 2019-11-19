#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;
	vector<bool> arr(n + 1);

	for (int i = 2; i <= n; ++i) {
		if (arr[i] == false) answer++; // ������ üũ�� �� �Ǿ��ִٸ�, �Ҽ�

		for (int j = i; j <= n; j += i)    // i�� 2�� �� 2,4,6,8 ... 2�� ��� �ε����� ��� true��
			arr[j] = true;
	}

	return answer;
}