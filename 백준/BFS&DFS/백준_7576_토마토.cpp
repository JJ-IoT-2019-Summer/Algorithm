#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 1001;
int N, M;

int arr[MAX][MAX];
bool visit[MAX][MAX];
int box[MAX][MAX];

queue <pair<int, int>> q;

int x_point[4] = { -1, 1, 0, 0 };
int y_point[4] = { 0,  0, -1, 1 };


void bfs() {

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {		// ó���� ���� �丶��� ��ġ �ľ�
			if (arr[i][j] == 1) {
				q.push(make_pair(i, j));	//ť�� ����
				visit[i][j] = true;			//�湮 ǥ��
				box[i][j] = 0;				// 0���� 
			}
		}
	}

	int new_y, new_x;
	pair<int, int> current;

	while (!q.empty()) {
		current = q.front();		
		q.pop();

		for (int i = 0; i < 4; i++) {
			new_y = current.first + y_point[i]; // �ֺ��� Ž�� 
			new_x = current.second + x_point[i];

			if (0 <= new_x && new_x < M && 0 <= new_y && new_y < N) {
				if (visit[new_y][new_x] || arr[new_y][new_x] == -1 || arr[new_y][new_x]== 1) continue; 
				// �丶�䰡 ���ų� �;����� ��������

				visit[new_y][new_x] = true;		//�ֺ��� ���� ���� �丶�䰡 ������ �湮
				arr[new_y][new_x] = 1;			//�丶�� ����
				q.push(make_pair(new_y, new_x));		//ť�� ����
				box[new_y][new_x] = box[current.first][current.second] + 1; // ������� �ɸ� ��  + 1
			}
		}
	}
	return;
}

int main()
{
	cin >> M >> N; //N�� ���� , M�� ����
			
	for (int i = 0; i < MAX; i++) {
		memset(visit[i], false, sizeof(bool) * MAX);
		memset(box[i], 0, sizeof(int) * MAX);
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	
	bfs();

	int max = -1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 0) {	// ���� ���� �丶�䰡 ���� ��� 
				cout << "-1" << endl;
				return 0;
			}
			else if (max < box[i][j]) max = box[i][j]; // ��� ���� �� ���� �ɸ� �� �� 
		}
	}
	cout << max << endl;

	return 0;

}