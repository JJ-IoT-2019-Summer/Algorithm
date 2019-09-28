#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

int T;
int h, w;

const int MAX = 1000;
int Dx[] = { 0,0,-1,1 };
int Dy[] = { -1,1,0,0 };
char map[MAX][MAX];
bool visit[MAX][MAX];


//���ʸ��� ���� �������� �������� ��������
//������ ���� ���� ����
//����̴� ���ʸ��� �������� ���� ĭ���� �̵�����
//���� ����� �� ����, ���� �Ű��� ĭ �Ǵ� ���� ���� �������� ĭ���� �̵�x
//����̰� �ִ� ĭ�� ���� �ŰܿŰ� ���ÿ� �ٸ� ĭ �̵� ����
// ������ Ż���ϴµ� ���� ���� �ð� ���, ������ Ż���� �� ������ �Ұ���	

// . : �����
// # : ��
// @ : ����� ��ġ
// '*' : ��
int solve() {
	int time = 0;

	memset(visit, false, sizeof(visit));
	queue<pair<int, int>> q;
	queue<pair<int, int>> fq;


	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (map[i][j] == '@') {
				visit[i][j] = true; //����� ��ġ
				q.push({ i, j }); // y, x
		
			}
			else if (map[i][j] == '*') { // �� ��ġ �Է� 
				fq.push({ i, j }); // y, x
			}
		}
	}

	bool exit = false;
	while (!q.empty()) {
		time++; // �ð� ����

		int current_move = q.size();
		for (int m = 0; m < current_move; ++m) { // 1�ʿ� ����̰� �̵��� �� �ִ� ��� Ȯ��
			int y = q.front().first;
			int x = q.front().second; // �̹� ��ġ�� x, y ��ǥ

			q.pop();

			if (map[y][x] == '*') continue;  // �̹� ����� ��ġ�� ���� �ִ� ���̸� ������ Ȯ��.

			for (int i = 0; i < 4; ++i) { // ���� Ż�� �������� 4���⿡ ���� �̵� Ȯ��
				int ny = y + Dy[i];
				int nx = x + Dx[i];

				if (nx < 0 || nx >= w || ny < 0 || ny >= h) {  // ���� ��ġ�� map ���̸� ����� Ż��
					exit = true;
					break;
				}

				if (map[ny][nx] == '.' && visit[ny][nx] == false) { // ���� ��ġ�� �� �����̰� �湮�� �� ������
					visit[ny][nx] = true; // �湮 ǥ�� 
					q.push({ ny,nx });  // ����� �湮 ť�� �߰� 
				}
			}

		}
		if (exit) return time; // ����̰� ������ Ż�������� �ݺ��� break �ƴ϶�� �� �̵�

			int current_fmove = fq.size(); // �̹� �ð��� ���� ������ �� �ִ� ����

			for (int m = 0; m < current_fmove; ++m) {
				int y = fq.front().first;
				int x = fq.front().second; // �̹� �� ��ġ�� x,y ��ǥ
				fq.pop();

				for (int i = 0; i < 4; ++i) { // �� 4���� �̵� Ȯ��
					int ny = y + Dy[i];
					int nx = x + Dx[i];

					if (nx < 0 || nx >= w || ny < 0 || ny >= h) continue; // �� ������ ������ Ȯ�� x

					if (map[ny][nx] == '.') { // ���� �̵� ��Ұ� �� �����̶�� 
						map[ny][nx] = '*'; // �ҷ� ���� 
						fq.push({ ny,nx });  // �� �湮 ť�� �߰� 
					}
				}
			}
	}

	return -1;
}
int main()
{
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> w >> h;
		memset(map, 0, sizeof(map));
		for (int i = 0; i < h; ++i) {
			getchar(); // �Է� ���� ����
			for (int j = 0; j < w; ++j) {
				map[i][j] = getchar(); //�� ���ھ� �ޱ� 
			}
		}

		int result = solve();
		if (result == -1) cout << "IMPOSSIBLE" << endl;
		else cout << result << endl;

	}

	return 0;
}