#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
/*
�� �׸��� ũ�Ⱑ 5�� ���� �ﰢ���� �� ����̴�.

�� ���� 7���� �����ؼ� �Ʒ��� �ִ� �� �� �ϳ��� �����Ͽ� �Ʒ������� ������ ��,
�������� ���õ� ���� ���� �ִ밡 �Ǵ� ��θ� ���ϴ� ���α׷��� �ۼ��϶�.
�Ʒ����� �ִ� ���� ���� ������ ���õ� ���� �밢�� ���� �Ǵ� �밢�� �����ʿ� �ִ� �� �߿����� ������ �� �ִ�.

�ﰢ���� ũ��� 1 �̻� 500 �����̴�. �ﰢ���� �̷�� �ִ� �� ���� ��� �����̸�, ������ 0 �̻� 9999 �����̴�.
*/
int main() {
	int n;

	cin >> n;
	int **arr = new int*[n + 1];
	int **DP = new int*[n + 1];

	for (int i = 0; i < n + 1; i++) {
		arr[i] = new int[n + 1];
		DP[i] = new int[n + 1];
		memset(arr[i], 0, sizeof(int)*n + 1);
		memset(DP[i], 0, sizeof(int)*n + 1);
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			cin >> arr[i][j];
		}
	}

	DP[0][0] = arr[0][0];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			if (j == 0)  //i�� ° �� ���� ������ ��� 
				DP[i][j] = DP[i - 1][j] + arr[i][j];

			else if (i == j)  //i�� ° �� �߰��� ��� 
				DP[i][j] = DP[i - 1][j - 1] + arr[i][j];

			else  //i�� ° �� ���� �������� ��� 
				DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - 1]) + arr[i][j];

		}

	}

	int MAX = DP[n - 1][0];

	for (int i = 0; i < n; i++)
		if (DP[n - 1][i] > MAX)
			MAX = DP[n - 1][i];

	cout << MAX << endl;


}