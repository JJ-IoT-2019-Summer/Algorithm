#include <iostream>
#include <vector>
using namespace std;

int const MAX = 128;
int N;
int arr[MAX][MAX];

int white = 0;
int blue = 0;

void dfs(int n, int start_x, int start_y) {
	int color = arr[start_y][start_x]; // ���� ��ġ�� �� 

	for (int i = start_y; i < start_y + n; ++i) {
		for (int j = start_x; j < start_x + n; ++j) {
			if (arr[i][j] != color) {					//���ҵ� ������ ���� ���� �ٸ��ٸ�?
				dfs(n / 2, start_x + n/2, start_y);		// ��1��и�
				dfs(n / 2, start_x, start_y);			 //��2��и�
				dfs(n / 2, start_x, start_y + n/2);		 //��3��и�
				dfs(n / 2, start_x + n/2, start_y+n/2);	 //��4��и�
				return;

			}
		}
	}
	if (color == 1) blue++; // ������� �Ķ����̸� �Ķ��� ���� �߰�
	else white++;
	
}
int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	dfs(N,0, 0); // 0,0

	cout << white << endl << blue << endl;

	return 0;

}