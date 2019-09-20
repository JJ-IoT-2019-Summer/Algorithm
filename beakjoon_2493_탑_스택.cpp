#include <iostream>
#include <stack>

using namespace std;
stack <pair<int, int>> st;
int result[500001] = { 0, };
int N;

int main() {

	int height;

	cin >> N;
	cin >> height;

	st.push(make_pair(1, height));

	for (int i = 1; i < N; i++) {
		cin >> height;

		if (height > st.top().second) {
			while (!st.empty() && st.top().second < height) {
				st.pop();
			}

			if (st.empty()) result[i] = 0;
			else {
				result[i] = st.top().first;		//���� ž�� ��ȣ�� �ε����� ž
				if (st.top().second == height) st.pop(); // �տ� ž�� ���� ž ������ �� �̻� ��ȣ�� ���� ����
			}
		}
		else {
			result[i] = st.top().first;		//���� ž�� ��ȣ�� �ֱ� ž�� �ε���.
		}


		st.push(make_pair(i + 1, height)); // 1���� �־����Ƿ� 2���� �ֱ� ���� i+1
	}

	for (int i = 0; i < N; i++)
		cout << result[i] << " ";

	return 0;
}