#include <iostream>
#include <cstring>
using namespace std;

// N = 1: 1              1��
// N = 2: 00 11          2�� 
// N = 3: 001 100 111    3��   => N = 1 +  N = 2 
// N = 4: 0000 0011 1100 1001 1111  5�� => N = 2 + N = 3 
// N = 5: 00001 10000 11111 11100 00111 00100 10011 11001 �̹Ƿ� 8�� => N = 3 �� ��  3  +  N = 4 �� �� 5
// �ᱹ�� �Ǻ���ġ ����
int main() {
	int N;

	cin >> N;

	int tile[1000001];
	memset(tile, 0, sizeof(tile));
	tile[0] = 1;
	tile[1] = 2;

	for (int i = 2; i <= N; i++)	//�Ǻ���ġ 
		tile[i] = (tile[i - 1] + tile[i - 2]) % 15746; //N�� 1,000,000 ���� �̸� int ������ ǥ���� ���� 
													 // => �������� 15746�� ������ �䱸�����Ƿ� �������� ����

	cout << tile[N - 1] << endl;

	return 0;
}