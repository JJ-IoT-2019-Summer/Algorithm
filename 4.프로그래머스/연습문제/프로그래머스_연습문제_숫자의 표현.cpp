#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
	int answer = 0;
	int sum = 0, temp = 0;

	for (int i = 1; i < (n / 2) + 1; ++i) { // ������ ���� ���ڸ� ���ϸ� ������ n �� ���ڸ� ����
		sum = 0;    // �� �ʱ�ȭ
		temp = i;   // �ʱ� ����  ����
		while (sum < n) 
			sum += temp++; //���ӵ� ���� �հ�
		
		if (sum == n) //���ӵ� ���� ���� n�� ���ٸ� 
			answer++; // �� ����
		
	}
	return answer + 1;

}

int main() {

	cout << solution(15);
}