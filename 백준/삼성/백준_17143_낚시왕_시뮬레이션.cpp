#include <iostream>
#include <cstring>   // memcpy , memset
using namespace std;

struct Shark {
	int s, d, z; //s = spped , d = direct , z = size
};

int Dc[] = {0,0,1,-1}; //��, �Ʒ�, ������, ���� ������
int Dr[] = {-1,1,0,-0};		//���� ������

int R, C, M;  //R(row)  ���� ũ��, C(column) ���� ũ��, M ��� ��
int r, c, s, d, z = 0;

Shark arr[100][100];


int solve() {
	int sum = 0;

	Shark backup[100][100];

	for (int t = 0; t < C; ++t) { // ���ÿ��� ���ʿ��� ����������

		for (int j = 0; j < R; ++j) { // ���ÿ����� ���� ����� ������
			if (arr[j][t].z > 0) {   //�� �ִٸ�? 
				sum += arr[j][t].z; // ���ÿ��� �� ����
				arr[j][t].z = 0;
				break;              //1 ���� ��� ��� ������ break
			}
		}

		memcpy(backup, arr, sizeof(arr)); // backup �迭�� ���� ��� ��ġ ���
		memset(arr, 0, sizeof(arr)); // ���� �� 0 ���� set 

		for (int i = 0; i < R; ++i) { // ������ row => ����
			for (int j = 0; j < C; ++j) {
				Shark& curr = backup[i][j]; // ���۷��� ����, alias �� ���
				if (curr.z > 0) {			// �� ������ �̵�
					int new_row = i + curr.s * Dr[curr.d]; //���ο� �� = ��� �ӵ� * ����
					int new_col = j+ curr.s * Dc[curr.d]; //���ο� �� = ��� �ӵ� * ����

					if (new_row < 0 ) { // ���� �̵��ϸ鼭 �������� ����� ���
						new_row = -new_row; // �Ʒ� �������� ������ �ٲپ���
						curr.d = 1;
					}
					if (new_row > R - 1) {  // �Ʒ��� �̵��ϸ鼭 �������� ����°��
						int q = new_row / (R - 1); // ���� ¦���̸� �Ʒ� ����, Ȧ���̸� ������
						int r = new_row % (R - 1); // row �� ��� ��ġ ����
						if (q % 2 == 0) {         //�Ʒ� ����
							new_row = r;
						}
						else {
							new_row = (R - 1) - r; // row �� ��� ��ġ ����
							curr.d = 0; // �� ����
						} 
					}

					if (new_col < 0) {  // �������� �̵��ϸ鼭 �������� ����� ���
						new_col = -new_col;
						curr.d = 2; // ������ �������� ����
					}
					if (new_col > C - 1) { //���������� �̵��ϸ鼭 ������ ����� ���
						int q = new_col / (C - 1);
						int r = new_col % (C - 1);
						if (q % 2 == 0) {   //������ ����
							new_col = r;
						}
						else {   //���� �����ΰ�� 
							new_col = (C - 1) - r;
							curr.d = 3;
						}
					}
					//�������� ����� ���ο� ��ġ ���

					if (arr[new_row][new_col].z < curr.z) {
						//���ʿ��� �׳� �ְ�, �̹� �ִٸ�? ��ū��쿡�� �Է�
						arr[new_row][new_col] = curr; // ��� �迭�� �����صξ��� �� ���ο� ��ġ��
					}
				}
			}
		}
	}
	return sum;

}
int main() {
	cin >> R >> C >> M;
	for (int i = 0; i < M; i++) {
		cin >> r >> c >> s >> d >> z; // �ʱ� �Է� 
		arr[r - 1][c - 1] = { s, d - 1, z };
		// 0,0 ���� ����ϱ� ���� r-1, c-1  
		// direct�� 0 ���ͻ���ϱ� ���� -1
	}
	cout << solve() << endl;

	return 0;
}