#include <iostream>
#include <queue>

using namespace std;

const int MAX = 20;

struct SHARK {  //�� ������ �ִ� Ư��
	int y, x, time; // time �� ����⸦ ��� ���������� �ɸ��� �ð�
};


int map[MAX][MAX];
int N;

int Dy[] = { -1,1,0,0 };
int Dx[] = { 0,0,1,-1 };

int shark_size, shark_eat; //����� ũ��� ���� ����� ��
SHARK shark; //���� �ִ� ����� ���� 

int solve() {
	int answer=0;

	bool is_map_update = true;

		while (is_map_update) { // �� ���� �� �ִ� ����Ⱑ ���� ������ 
			is_map_update = false;

			bool visited[MAX][MAX] = { false, }; //�� ���� ���� ���� visited ���
			visited[shark.y][shark.x] = true;    //���� ��� ��ġ �湮 ǥ��

			queue<SHARK> q; //���帶�� ���ο� ť�� �ְ� ����� ��ġ ����
			q.push(shark);

			SHARK favorite; // �� ���� ����� ����
			favorite.y = 20; favorite.time = -1; // ������ ���� ū ������ y�ʱ�ȭ
						   						//�� ������ y�� ���� ���� �����(����) �� ���� �Ա� ���� 

			while (!q.empty()) {  // ����� ��ġ �ľ� 
				SHARK cur = q.front(); q.pop();

				if (favorite.time != -1 && favorite.time < cur.time)
					break; // �������� ������� �ð��� ���纸�� ������ �� �ʿ� ����
							//���� ����� ������ ��Ҵٶ�� �Ǵ�
				
				if (map[cur.y][cur.x] < shark_size && map[cur.y][cur.x]!=0) { //�� ����⸦ ���� �� �ִٸ�
					is_map_update = true; //���� ����Ⱑ �ִ�  ǥ��

					//�������� ������ �� ���ʿ� �ְ� ���� ���ʿ� �ִ� �������� Ȯ��
					if (favorite.y > cur.y || (favorite.y == cur.y && favorite.x > cur.x)) {
						favorite = cur;
					}

				}

				for (int dir = 0; dir < 4; ++dir) { // 4�������� Ž���� ���� 
					SHARK next;
					next.y = cur.y + Dy[dir];
					next.x = cur.x + Dx[dir]; //4 �������� �̵�
					next.time = cur.time + 1;

					if (next.y < 0 || next.y >= N || next.x < 0 || next.x >= N) continue; //�ǹ����� ������ ���� Ȯ�� 

					//�湮���� ���� ������� ũ�Ⱑ ����� ũ�⺸�� ������ 
					if (visited[next.y][next.x] == false && map[next.y][next.x] <= shark_size) {
						visited[next.y][next.x] = true;
						q.push(next);
					}
				}

			}

			if (is_map_update) { // ���� �� �ִ� ����Ⱑ ������
				shark = favorite;
				++shark_eat;
				if (shark_eat == shark_size) {
					++shark_size;
					shark_eat = 0;
				}
				map[shark.y][shark.x] = 0;  //����� �԰� �� ����

			}

		}

	answer = shark.time;
	return answer;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {  //�����
				shark.x = j; shark.y = i;
				shark.time = 0;
				shark_size = 2; shark_eat = 0; // �ʱ� ��� �� ����
				map[i][j] = 0;  // �� ���߿� �� ��ġ�� �̵� �� �� �ֵ��� ����
			
			}
		}
	}

	cout << solve();
}