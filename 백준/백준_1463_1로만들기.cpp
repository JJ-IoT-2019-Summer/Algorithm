#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

//���� X�� ����� �� �ִ� ������ ������ ���� �� ���� �̴�.
//
//X�� 3���� ������ ��������, 3���� ������.
//X�� 2�� ������ ��������, 2�� ������.
//1�� ����.
//���� N�� �־����� ��, ���� ���� ���� �� ���� ������ ����ؼ� 1�� ������� �Ѵ�.������ ����ϴ� Ƚ���� �ּڰ��� ����Ͻÿ�.

int N;
int DP[1000001];
int cnt = 0;

int main()
{
	memset(DP, 0, sizeof(int) * 1000001);
	cin >> N;

	DP[1] = 0;

	for (int i = 2; i <= N; i++) {
		DP[i] = DP[i - 1] + 1; //1�� ���� ��� 
		if (i % 2 == 0) DP[i] = min(DP[i], DP[i / 2] + 1); // 2���� ���������� ��� 
		if (i % 3 == 0) DP[i] = min(DP[i], DP[i / 3] + 1); // 3���� ���������� ���  
	}

	cout << DP[N] << endl;;
	return 0;
}