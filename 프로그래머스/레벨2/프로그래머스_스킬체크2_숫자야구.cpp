#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> baseball) {
	int answer = 0;

	for (int i = 123; i <= 987; i++) {
		int a = i / 100; // ���� �ڸ� 
		int b = (i / 10) % 10; // ���� �ڸ�
		int c = (i % 10); //���� �ڸ�

		if (a == 0 || b == 0 || c == 0) continue; // ���ڰ� 0�� ��� ����
		if ((a == b) || (b == c) || (c == a)) continue; //���� ��� ���� 

		for (int j = 0; j < baseball.size(); j++) {
			int strike = 0; int ball = 0;

			int expt_num = baseball[j][0]; //���� ���� ����
			int expt_a = expt_num / 100; // ���� �ϴ� ������ ���� �ڸ�
			int expt_b = (expt_num / 10) % 10; // ���� �ϴ� ������ ���� �ڸ�
			int expt_c = (expt_num % 10); // ���� �ϴ� ������ ���� �ڸ� 

			if (a == expt_a) strike++; // �ڸ����� ������ strike
			if (b == expt_b) strike++;
			if (c == expt_c) strike++;

			if (strike != baseball[j][1]) break; // ��Ʈ����ũ�� ������ �ٸ��� �ش� ��� Ȯ�� X

			if (a == expt_b || a == expt_c) ball++;
			if (b == expt_c || b == expt_a) ball++;
			if (c == expt_a || c == expt_b) ball++;
			if (ball != baseball[j][2]) break; //���� ������ �ٸ��� �ش� ��� Ȯ�� X

			if (j == baseball.size() - 1) answer++;

		}
	}

	return answer;
}