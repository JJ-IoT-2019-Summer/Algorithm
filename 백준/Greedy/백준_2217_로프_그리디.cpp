#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> rope;
vector<int> sum;
int main() {
	cin >> N;
	int num = 0;

	for (int i = 0; i < N; i++) {
		cin >> num;
		rope.push_back(num);
	}

	sort(rope.begin(), rope.end(), greater<int>());  // ������ ��ƿ �� �ִ� ��ü�� �ִ� �߷��� ���� �������� ����

	for (int i = 0; i < rope.size(); i++) {  //  ���� ����� ���� �� �ִ� �߷��� ��ƿ �� �ִ� ������ ��� �� ��� �� ������ ��� �����ϹǷ� *1
		sum.push_back(rope[i] * (i + 1));   // �� ��°�� �߷��� ���� ��Ƽ�� ������ ����ϸ� �ִ��߷��� 2��° �߷� ������ �����ϹǷ� *2
	}

	num  = *max_element(sum.begin(), sum.end()); // �� �������� ���ķ� ��ƿ �� �ִ� ���� �� �ִ��� ���Ը� ������ 
	cout << num;

	return 0;
}