#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <queue>

using namespace std;

struct path
{
	int x, y, time;
};

const int MAX = 101;

int shortest_path = 987654321;

int Dy[] = { -1,1,0,0 };
int Dx[] = { 0,0,-1,1 };

int map[MAX][MAX] = { 0, };
int dist[MAX][MAX] = { 0, };


int T = 0;
int N = 0;


int BFS() {
	queue<path> q;
	q.push({ 0,0,1 }); //���� ��ġ , time�� 0���� �ϸ� �ȵ�

	while (!q.empty()) {

		int x = q.front().x;  // ���� Ȯ�� ��ġ 
		int y = q.front().y;
		int time = q.front().time;
		q.pop();

		//�������� ������ �������� ��� �� �ּҰ��� ���� ���ã��
		if (x == N - 1 && y == N - 1) {
			if (shortest_path > time) shortest_path = time;
			continue;
		}

		for (int dir = 0; dir < 4; dir++) {
			int ny = x + Dy[dir];
			int nx = y + Dx[dir];

			//���ο� ��ġ�� �� ���� ��� ����ó��
			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;

			// ���� ��ġ���� ���ο� ��ġ(ny,nx) �� ���� ����� �ð��� 
			// ���� ª�ٰ� ������ ����� �ð����� ���� ���, ������Ʈ
			if (dist[ny][nx] == 0 || time + map[ny][nx] < dist[ny][nx]) {
				q.push({ ny, nx, time + map[ny][nx] });
				dist[ny][nx] = time + map[ny][nx];

			}

		}
	}

	return  shortest_path - 1;
}

int main() {
	cin >> T;
	for (int i = 1; i < T + 1; ++i) {
		cin >> N;

		memset(map, 0, sizeof(map)); //map �ʱ�ȭ
		memset(dist, 0, sizeof(dist)); //dist �ʱ�ȭ
		shortest_path = 987654321;

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				scanf("%1d", &map[i][j]);
			}
		}

		cout << "#" << i << " " << BFS() << endl;

	}
	return 0;
}