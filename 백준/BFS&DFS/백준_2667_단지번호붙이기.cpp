#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;


//<�׸� 1>�� ���� ���簢�� ����� ������ �ִ�. 1�� ���� �ִ� ����, 0�� ���� ���� ���� ��Ÿ����.
//ö���� �� ������ ������ ����� ������ ������ ������ �����ϰ�, ������ ��ȣ�� ���̷� �Ѵ�.
//���⼭ ����Ǿ��ٴ� ���� � ���� �¿�, Ȥ�� �Ʒ����� �ٸ� ���� �ִ� ��츦 ���Ѵ�.
//�밢���� ���� �ִ� ���� ����� ���� �ƴϴ�. <�׸� 2>�� <�׸� 1>�� �������� ��ȣ�� ���� ���̴�
//.������ �Է��Ͽ� �������� ����ϰ�, �� ������ ���ϴ� ���� ���� ������������ �����Ͽ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

int N;
int arr[26][26];
bool visit[26][26];  //�� �湮 ���� Ȯ��

int x_point[4] = { 1,0,-1,0 };   // 4 �������� ������ ���� �����ϴ��� Ȯ��
int y_point[4] = { 0,-1,0,1 };

int cnt = 0; //���� �� 
int num_resident[1000] = { 0, }; // ������ ���� ���� 

int DFS(int y, int x) {

	visit[y][x] = true; // �湮 üũ
	num_resident[cnt]++; // ������ ���� �� ����

	for (int z = 0; z < 4; z++) {
		int new_x = x + x_point[z];
		int new_y = y + y_point[z];

		if (0 <= new_x && new_x < N && 0 <= new_y && new_y < N) {
			if (visit[new_y][new_x] == false && arr[new_y][new_x]) DFS(new_y, new_x);
			// ������ �湮���� ���� �� �����ϸ� DFS
		}
	}
	return 0;
}
int main()
{
	cin >> N;
	for (int i = 0; i < 26; i++) {
		memset(arr[i], 0, sizeof(int) * 26);
		memset(visit[i], false, sizeof(bool) * 26);	//�ʱ�ȭ
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &arr[i][j]);	//���� �Է�
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] && visit[i][j] == false) { // ���� �� ���� ���������� ����
				DFS(i, j);
				cnt++; //���� ����
			}
		}
	}

	cout << cnt << endl;
	sort(num_resident, num_resident + cnt); // �������� 

	for (int i = 0; i < cnt; i++) {
		cout << num_resident[i] << endl;
	}

	return 0;
}