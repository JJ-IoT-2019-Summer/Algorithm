#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N;
int arr[18][18] = { 0, };
int DP[3][18][18] = { 0, };
int r, c = 0;


//DP �Ǵ� BFS �Ѵ� ����


struct pipe { //�������� �Ӽ�  => ����, ��ġ
	int direction, x, y;
};

//DP ����
//D[0][X][Y] : ���� ��������(X, Y)�� �����ϴ� ����� ��
//D[1][X][Y] : ���� ��������(X, Y)�� �����ϴ� ����� ��
//D[2][X][Y] : �밢�� ��������(X, Y)�� �����ϴ� ����� ��
//D[0][1][2] = 1 : ���� ������ ���� ��ġ(1, 2)
//��ó : https ://rebas.kr/838 [PROJECT REBAS]


int solve() {
	DP[0][0][1] = 1;    //�ʱ⿡ ������ 0,0 , 0,1 => �������� �Ӹ��� x =1 y = 0 �� ��ġ, ������ ���η�

	for (int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			if (arr[i][j + 1] == 0) DP[0][i][j + 1] += DP[0][i][j] + DP[2][i][j];   //���� �������� �� �� �ִ� ��� => ���� ����-> ���ι��� �Ǵ� �밢������ -> ���ι���
			if (arr[i + 1][j] == 0) DP[1][i+1][j] += DP[1][i][j] + DP[2][i][j];   //���� �������� �� �� �ִ� ��� => ���� ����-> ���ι��� �Ǵ� �밢������ -> ���ι���
			if (arr[i + 1][j + 1] == 0 && arr[i + 1][j] == 0 && arr[i][j + 1] == 0) 
				DP[2][i + 1][j + 1] += DP[0][i][j] + DP[1][i][j] + DP[2][i][j]; // �� �������� i, j �� ���� �ϴ� ����� �� + �밢������ i+1 , j+1 ���� ���� �� 
		}
	}

	return DP[0][N-1][N-1]+ DP[1][N - 1][N - 1]+ DP[2][N - 1][N - 1];
}

int Dx[] = { 0,1,1 }; // 0: ����, 1: �밢�� , 2: ����
int Dy[] = { 1,1,0 };

int solve_bfs() {
	int cnt = 0; // n-1, n-1 ������ ���� ����� �� 

	queue<pipe> q;
	q.push({ 2, 1, 0 });   //�ʱ⿡ ������ 0,0 , 0,1 => �������� �Ӹ��� x =1 y = 0 �� ��ġ, ������ ���η�

	while (!q.empty()) {
		pipe curr = q.front(); //������ �Ӹ� �κ� ��ǥ�� ����
		q.pop();

		if (curr.x == N - 1 && curr.y == N - 1)
			cnt++; //���� ����

		int start = 0;
		int end = 0;
		if (curr.direction == 0) {  // ���� �� ��� ����, �밢�� �̵� ��� Ȯ��
			start = 0;
			end = 2;
		}
		else if (curr.direction == 1) // �밢�� �� ��� ����, �밢��,����  �̵� ��� Ȯ��
		{
			start = 0;
			end = 3;
		}
		else if (curr.direction == 2) {// ���� �� ��� ����, �밢�� �̵� ��� Ȯ��
			start = 1;
			end = 3;
		}

		for (int i = start; i < end; ++i) {
			int ny = curr.y + Dy[i];
			int nx = curr.x + Dx[i];
			int ndirection = i;

			if (nx < N && ny < N && arr[ny][nx] == 0) {
				if (ndirection == 0 || ndirection == 2) // ����  �Ǵ� ���� �̵��̸� 
					q.push({ ndirection, nx, ny });
				else if (ndirection == 1 && !arr[ny][nx - 1] && !arr[ny - 1][nx]) {
					// �밢���̸鼭 �̵��Ϸ��� ��ġ�� ��, ������ ���� ����� ��
					q.push({ ndirection,nx,ny });
				}
			}
		}
	}

	return cnt;

}


int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) { // 1,1 �� �ƴ϶� 0,0 ���� ���� N-1����
			cin >> arr[i][j];
		}
	}

	cout << solve();

	return 0;
}