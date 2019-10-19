//https://www.acmicpc.net/problem/17143

#include <iostream>
#include <cstring>   // memcpy , memset
using namespace std;

struct Shark {
	int s, d, z; //s = spped , d = direct , z = size
};

int Dc[] = { 0,0,1,-1 }; // �����¿� �̵�
int Dr[] = { -1,1,0,0 };

int R, C, M;  //R(row) �迭�� yũ��, C(column) �迭�� xũ��, M  ����Ǽ�
int r, c, s, d, z = 0;

Shark arr[100][100];


int solve() {
	int sum = 0;

	Shark backup[100][100];

	for (int t = 0; t < C; ++t) { //  ���η� �̵��ϸ鼭 

		for (int j = 0; j < R; ++j) { // ������ ����
			if (arr[j][t].z > 0) {   // ����� ũ�Ⱑ 0 �Ͻ� 
				sum += arr[j][t].z; // �� ������, ũ�⸦ ������
				arr[j][t].z = 0;    // �� ��ġ�� ���� �����Ƿ� 0
				break;              //�������κ��� ����� �� ������Ƿ� break
			}
		}

		memcpy(backup, arr, sizeof(arr)); // backup�� arr ����(��� ��ġ��)
		memset(arr, 0, sizeof(arr)); // ������ġ�� ���� ���� �ʱ�ȭ

		for (int i = 0; i < R; ++i) { // ��� ��ġ�� �� Ȯ���ϱ� ���� ���� ��
			for (int j = 0; j < C; ++j) { // ���� 
				Shark& curr = backup[i][j]; // �����ϰ� ���� ���� ���۷��� ����, alias
				if (curr.z > 0) {		// ���� ��� ��ġ 
					int new_row = i + curr.s * Dr[curr.d]; //���� ��ġ 
					int new_col = j + curr.s * Dc[curr.d]; 
					//���� ������ �����̶�� Dr �� 0�̰� 0* �ӵ� �̹Ƿ� ��,�� ��ȭ X

					if (new_row < 0) { // ���� �������� ����� ��� 
						new_row = -new_row; // ������ ����� (�Ʒ���) 
						curr.d = 1;      //���� 
					}

					if (new_row > R - 1) {  // �Ʒ� �������� ��� ���
						int q = new_row / (R - 1);  //���� 
						int r = new_row % (R - 1); // ��ġ
						if (q % 2 == 0) {         //���� ¦���̸� �Ʒ� ����
							new_row = r;     //���� �׷���, ������ġ�� ������
						}
						else {
							new_row = (R - 1) - r; //������ ��ǥ���� ������ ����
							curr.d = 0; // Ȧ���� ��� ������ �ٲ��
						}
					}

					if (new_col < 0) {  // �·� �������� ����� ��� 
						new_col = -new_col;
						curr.d = 2; // ������ �������� �ٲ��ֱ�
					}
					if (new_col > C - 1) { // ���������� ������ ���� ����� ���
						int q = new_col / (C - 1);
						int r = new_col % (C - 1);
						if (q % 2 == 0) {   //�������� ���� ��ġ 
							new_col = r;
						}
						else {   // ������ ���� ��ġ���� ������ ��
							new_col = (C - 1) - r;
							curr.d = 3; // ����
						}
					}

					//���ο� ��ġ�� ����� ũ�⺸�� ���� ����� ũ�Ⱑ ũ�ٸ�
					if (arr[new_row][new_col].z < curr.z) 
									arr[new_row][new_col] = curr;
					//���ο� ��ġ�� �̵�
					
				}
			}
		}
	}
	return sum;  //���� ��� ũ���� �� 

}
int main() {
	cin >> R >> C >> M;
	for (int i = 0; i < M; i++) { //  ����� �� ��ŭ �ݺ���
		cin >> r >> c >> s >> d >> z; // ����� ����
		arr[r - 1][c - 1] = { s, d - 1, z };
		// 0,0 ���� �����ϹǷ� r-1,c-1 �� ����� ���� �Է�
		// direct�� 0 ���� �����ϹǷ� -1
	}
	cout << solve() << endl;

	return 0;
}