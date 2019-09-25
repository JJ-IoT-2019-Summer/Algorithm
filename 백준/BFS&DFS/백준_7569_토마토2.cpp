#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 101;
int N, M, H; // M�� ������ ���� ĭ�� ��, N�� ������ ���� ĭ�� ���� ��Ÿ����.

int arr[MAX][MAX][MAX];
bool visit[MAX][MAX][MAX];
int box[MAX][MAX][MAX];

queue <pair<int,pair<int, int>>> q;

int Dx[] = { -1, 1, 0, 0,0,0 };
int Dy[] = { 0,  0, -1, 1 ,0,0 };
int Dz[] = { 0,0,0,0,-1,1 };   

void bfs() {

	for (int k = 0; k < H; k++)
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {		// ó���� ���� �丶��� ��ġ �ľ�
				if (arr[k][i][j] == 1) {
					q.push(make_pair(k,make_pair(i, j)));	//ť�� ����
					visit[k][i][j] = true;			//�湮 ǥ��
					box[k][i][j] = 0;				// 0���� 
				}
			}
		}

	int new_y, new_x, new_z;
	pair<int,pair<int, int> >current;

	while (!q.empty()) {
		current = q.front();
		q.pop();

		for (int i = 0; i < 6; i++) {
			new_y = current.second.first + Dy[i]; // �ֺ��� Ž�� 
			new_x = current.second.second + Dx[i];
			new_z = current.first + Dz[i];

			if (0 <= new_x && new_x < M && 0 <= new_y && new_y < N &&0 <= new_z && new_z < H) {
				if (visit[new_z][new_y][new_x] || arr[new_z][new_y][new_x] == -1 || arr[new_z][new_y][new_x] == 1) continue;
				// �丶�䰡 ���ų� �;����� ��������

				visit[new_z][new_y][new_x] = true;		//�ֺ��� ���� ���� �丶�䰡 ������ �湮
				arr[new_z][new_y][new_x] = 1;			//�丶�� ����
				q.push(make_pair(new_z, make_pair(new_y, new_x)));		//ť�� ����
				box[new_z][new_y][new_x] = box[current.first][current.second.first][current.second.second] + 1; // ������� �ɸ� ��  + 1
			}
		}
	}
	return;
}

int main()
{
	cin >> M >> N >> H; //N�� ���� , M�� ���� , H�� ���� 


	memset(visit, false, sizeof(bool) * MAX);
	memset(box, 0, sizeof(int));

	for (int k = 0; k < H; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				cin >> arr[k][i][j];
		
	bfs();

	int max = -1;
	for (int k = 0; k < H; k++)
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (arr[k][i][j] == 0) {	// ���� ���� �丶�䰡 ���� ��� 
					cout << "-1" << endl;
					return 0;
				}
				else if (max < box[k][i][j]) max = box[k][i][j]; // ��� ���� �� ���� �ɸ� �� �� 
			}
		}
	cout << max << endl;

	return 0;

}
