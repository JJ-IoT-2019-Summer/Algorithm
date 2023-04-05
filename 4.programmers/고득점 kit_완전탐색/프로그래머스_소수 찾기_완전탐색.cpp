#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>


using namespace std;
bool arr[10000000] = { false, };


bool checkPaper(int i, string numbers) {
	bool flag = false;
	vector<bool> visit(numbers.size()); //���ڸ�ŭ visit �迭 ����

	while (i != 0) { //�Ҽ��� �Ǻ��� ���� digit���� ���� 
		flag = false;
		int digit = i % 10;

		for (int j = 0; j <= numbers.size(); ++j) {
			if (digit == numbers[j] - '0' && visit[j] == false) {
				flag = true;  //digit �� ���̿� ���� �����̸� �÷��� Ȯ��
				visit[j] = true;
				break;
			}
		}

		if (flag == false) return false; //���� ��������� ������ ���� �����̹Ƿ� false ����
		i = i / 10;       // �Ҽ��� digit ��ΰ� ���̿� �����ִ��� Ȯ���ϱ� ���� �ٽ� digit �� �ɰ�   
	}
	return true;
}

int solution(string numbers) {
	int answer = 0;
	vector<int> prime;

	sort(numbers.begin(), numbers.end(), greater<char>());
	int range_max = stoi(numbers);

	for (int i = 2; i <= range_max; i++) {
		if (arr[i] == false && checkPaper(i, numbers)) { //�Ҽ��̸鼭 ���̿� ���� ���ڸ� ���
			cout << i << endl;
			answer++;
		}
		if (arr[i] == false) { //�Ҽ�
			for (int j = i; j <= range_max; j += i) { //�Ҽ��� ����� �Ҽ��� �ƴ�
				arr[j] = true;
			}
		}
	}
	return answer;
}