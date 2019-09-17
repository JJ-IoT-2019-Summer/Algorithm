#include <string>
#include <vector>

using namespace std;
int answer = -1;

void dfs(int N, int min, int num, int number) {
	if (min > 8) return; // �ּڰ��� 8���� ũ�� -1�� return 
	if (num == number) {  // ���� ����, num �̶�� ������ ���ڸ� �����ذ��� �Է��� ���� number�� ��������
		if (min < answer || answer == -1) {  // ���� �ּڰ��� ������ ���� answer ���� �۰ų� answer �� -1 �� ���
			answer = min; // answer�� �ּڰ����� ����
		}
		return;
	}

	int NN = 0;
	for (int i = 0; i < 8; i++) {	// 8�� �� ����ϱ� 
		NN = NN * 10 + N; // N, NN, NNN, NNNN ... NNNNNNNN

		// ù�� ° dfs ��  for �ݺ��� ���� : 0 +-*/ 5 -> ..... -> 0 +-*/ 55555555 

		// �ι� ° dfs ��  for �ݺ��� ���� : (0 + 5): 5 +-*/ 5 -> ..... -> 5 +-*/ 55555555 
		// - * / ������ �ȵ�    

		// ���� ° dfs ��  for �ݺ��� ���� : (5 + 5): 10 +-*/ 5 -> ..... -> 10 +-*/ 55555555
		// ���� ° dfs ��  for �ݺ��� ���� : (5 / 5): 1 +-*/ 5 -> ..... -> 1 +-*/ 55555555
		// ���� ° dfs ��  for �ݺ��� ���� : (5 * 5): 25 +-*/ 5 -> ..... -> 25 +-*/ 55555555
		//  - �� ��쿡�� 0 �̹Ƿ� ù��° dfs �ݿ��� ����
		// .... 

		dfs(N, min + 1 + i, num + NN, number); 
		dfs(N, min + 1 + i, num - NN, number);
		dfs(N, min + 1 + i, num * NN, number);
		dfs(N, min + 1 + i, num / NN, number);
	}
}

int solution(int N, int number) {
	dfs(N, 0, 0, number);
	return answer;
}