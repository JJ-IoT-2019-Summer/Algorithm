#include <string>
#include <vector>
#include <iostream>

#include <algorithm> 

using namespace std;

const int MAX = 200;
bool visited[MAX] = { false, };

int Dy[] = { 1,-1,0,0 };
int Dx[] = { 0,0,-1,1 };
int cnt = 0; // ��Ʈ��ũ �� 

int map[MAX][MAX] = { 0, };
int N = 0;

void DFS(int v, vector<vector<int>> computers) {
	visited[v] = true; // ��� V �湮 üũ


	for (int j = 1; j < computers.size(); j++)
		if (computers[v][j] && visited[j] == false) DFS(j, computers); 
	//��� v �� ����� ��ǻ���߿� �湮���� �ʾ����� �湮�ϱ� ���� DFS ���

}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	N = n;

	for (int i = 0; i < computers.size(); i++) {

		if (visited[i] == false) {  //��� i �� �湮���� �ʾ�����
			DFS(i, computers);
			cnt++; // ���ο� ��Ʈ��ũ �߰�
		}
	}


	return cnt;
}

int main() {
	int n = 3;
	vector<vector<int>> input{ {1, 1, 0}, { 1, 1,0 }, { 0, 0, 1 } };
	cout << solution(n, input);
	return 0;
}