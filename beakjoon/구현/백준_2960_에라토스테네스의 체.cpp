#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N, K;

bool backup[1001];
vector<pair<int, int>> v;

int del = 0;
int main() {

	int cnt = 0;
	cin >> N >> K; // K ��° ���촫 ��

	memset(backup, false, sizeof(backup));

	for (int i = 2; i < N + 1; ++i) {

		for (int j = i; j <= N; j += i) { // ���� i �� ������� backup array���� trueüũ
			if (backup[j] == false) { // ����� �Է��� �ȵ� ����
				backup[j] = true; //true
				cnt++;			//�� ��°�� üũ�Ǿ����� Ȯ��
				v.push_back(make_pair(j, cnt)); // ���� ���� �� ��° ������ ���Ϳ� ���
			}
		}
	}

	cout << v[K - 1].first << endl;

	return 0;
}