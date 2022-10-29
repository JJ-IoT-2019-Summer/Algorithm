#include <iostream>
#include <stdio.h>
#include <queue>

struct INFO {
	int ry, rx, by, bx, count;  //count �� ��� ���������� 
};

using namespace std;
const int MAX = 10;

char map[MAX][MAX + 1];
INFO start;
int visit[MAX][MAX][MAX][MAX] = { 0, };

int Dy[] = { -1,1,0,0 };
int Dx[] = { 0,0, -1,1 };

int bfs() {
	int ret = -1;
	queue<INFO> q;
	q.push(start);
	visit[start.ry][start.rx][start.by][start.bx] = 1; // �湮 ǥ�� 


	while (!q.empty()) {
		INFO cur = q.front(); q.pop();

		if (cur.count > 10) break;
		if (map[cur.ry][cur.rx] == 'O' && map[cur.by][cur.bx] != 'O') {
			ret = cur.count;
			break;
		}

		for (int i = 0; i < 4; ++i) {
			int next_ry = cur.ry;
			int next_rx = cur.rx;
			int next_by = cur.by;
			int next_bx = cur.bx;

			while (1) {  // ������ �̵�
				if (map[next_ry][next_rx] != '#' && map[next_ry][next_rx] != 'O') {
					next_ry += Dy[i]; next_rx += Dx[i];  // ��������� ��� ���� ����
				}
				else {
					if (map[next_ry][next_rx] == '#') {  // �������� �̵��ߴµ� ���̿��ٸ� 
						next_ry -= Dy[i]; next_rx -= Dx[i]; // �� �������� �̵� 
					}
					break;
				}
			}
			while (1) {  //�Ķ��� �̵�
				if (map[next_by][next_bx] != '#' && map[next_by][next_bx] != 'O') {
					next_by += Dy[i]; next_bx += Dx[i];  // ��������� ��� ���� ����
				}
				else {
					if (map[next_by][next_bx] == '#') {  // �������� �̵��ߴµ� ���̿��ٸ� 
						next_by -= Dy[i]; next_bx -= Dx[i]; // �� �������� �̵� 
					}
					break;
				}
			}
			if (next_ry == next_by && next_rx == next_bx) { //��ĭ�� ������, �Ķ����� ��� �ִ� ��� 
				if (map[next_ry][next_rx] != 'O') {  //������ ��쿡�� ���Ա� ������ ó�� ���ص� ��
					int red_dist = abs(next_ry - cur.ry) + abs(next_rx - cur.rx);
					//��������� ������ ���� �����Ÿ�, ���� ������ ����������� ���������� �𸣳� �� �� �ϳ��� 0
					int blue_dist = abs(next_by - cur.by) + abs(next_bx - cur.bx); //��������� �Ķ� ���� ������ �Ÿ�
					if (red_dist > blue_dist) {
						next_ry -= Dy[i]; next_rx -= Dx[i]; // ��ĭ �������� �̵� 
					}
					else {
						next_by -= Dy[i]; next_bx -= Dx[i]; // ��ĭ �������� �̵� 
					}
				}
			}
			if (visit[next_ry][next_rx][next_by][next_bx] == 0) { // ����� �� �湮������ ���� ���̶��?
				visit[next_ry][next_rx][next_by][next_bx] = 1; // �湮���� ǥ�� 
				INFO next;
				next.ry = next_ry;
				next.rx = next_rx;
				next.by = next_by;
				next.bx = next_bx;
				next.count = cur.count + 1;  //���ο� ��ġ�� ��� queue�� �ٽ� �ֱ� 
				q.push(next);
			}
		}
	}
	return ret;
}
int main() {
	int N, M; // N�� ���� (y), M�� ����(x)
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		getchar(); //���� ����
		for (int j = 0; j < M; ++j) {
			map[i][j] = getchar();
			if (map[i][j] == 'R') {
				start.ry = i, start.rx = j;
			}
			if (map[i][j] == 'B') {
				start.by = i, start.bx = j;
			}
		}
	}
	start.count = 0;
	cout << bfs() << endl;


	return 0;
}