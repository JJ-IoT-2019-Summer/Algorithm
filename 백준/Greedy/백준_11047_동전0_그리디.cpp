//https://www.acmicpc.net/problem/11047
#include <iostream>

//�� N�����̰�, ������ ������ �ſ� ���� ������ �ִ�.
//������ ������ ����ؼ� �� ��ġ�� ���� K

using namespace std;

int N;
int K;
int M = 0;
int arr[1000001] = { 0, };

int main() {
	cin >> N >> K;
	for (int i = 1; i < N+1; i++) {
		cin >> arr[i];
	}

	for (int i = N; i > 0; i--) {   // ex) 4200 ������ 
		M += K / arr[i];		    // arr[i] �� 4200 ���� ũ�� 0�� ������.
									//arr[i] �� K ���� ������ 4200 / 1000 => 4 (Ƚ��) �� M�� ������
		K = K % arr[i];				// 4200 % 1000 �̸� ������ 200 ���� K�� ���� 
								   //���� 4200 % 5000 �̿����� �������� 4200 �״��
	}
	cout << M;
}