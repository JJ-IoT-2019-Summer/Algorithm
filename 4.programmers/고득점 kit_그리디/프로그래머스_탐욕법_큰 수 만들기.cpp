#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
	string answer = "";
	int start = -1;
	int answer_size = number.size() - k; //return �Ǵ� ������ ũ��
	int new_j = 0;

	for (int i = 0; i < answer_size; i++) { //  k���� ������ ���� �ִ밪
		int max = -1;
		for (int j = start + 1; j < number.size() - (answer_size - i) + 1; j++) {  //range �� start+1 ~ �ڿ������� i�� ���� 
																		 //range �� ���� �ڷ� �̵�
			if (max < number[j] - '0') {//���� �� �� �� ���� ū �� ã�� , atoi ���
				max = number[j] - '0';
				new_j = j; // �ִ밪�� �ε��� ����
			}
		}

		answer.append(to_string(max)); // �ִ밪�� ���� ���� �̾� ���̱� 
		start = new_j; // �ڿ��� i ���� ������ �� �� ���� ū ������ �� �ڿ� ���� ã��
	}
	return answer;
}
int main() {
	string number = "4177252841";
	int k = 4;
	cout << solution(number, k);
}
