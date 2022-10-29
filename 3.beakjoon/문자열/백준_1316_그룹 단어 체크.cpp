#include <iostream>
#include <cstring>

using namespace std;

int N;
int visit[200];

int solve(string str) {

	int check = 0;
	for (int i = 0; i < str.length(); ++i) {
		if (visit[int(str[i])] == 0) { // ó�� ���Դٸ�
			int temp = int(str[i]);  //ó�� ���� ���ĺ��� ���
			while (1) {

				if (temp != str[i]) { //���������� ������ ���� ������
					--i;    //���������� ������ ���� ������ �ٽ� üũ�ϱ� ���� ����
					break;
				}
				visit[int(str[i])]++; // �� ���� 
				i++;

			}
		}
		else  // �׷� �ܾ �ƴ϶��
			return 0;
	}
	return 1;
}
int main() {
	int result = 0;
	cin >> N;
	string str;

	for (int i = 0; i < N; i++) {
		memset(visit, 0, sizeof(visit));
		cin >> str;
		result += solve(str);
	}

	cout << result;
	return 0;
}