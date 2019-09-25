#include <iostream>
#include <queue>
using namespace std;

int N, K; // N �� ����, K �� ����

int visit[100001] = { 0, };

int solve() {

	queue<pair<int, int>> q;
	q.push(make_pair(N, 0));

	while (!q.empty()) {

		pair<int, int> curr = q.front();  // ������

		q.pop();

		if (curr.first < 0 || curr.first >100000 || visit[curr.first]) continue; // ���� �� �Ǵ� �湮�ߴ� ���� continue

		if (curr.first == K) return curr.second; // ������� �ð� ����

		if (visit[curr.first] == 0) visit[curr.first] = 1; // �湮���� ������ �湮ǥ��

		q.push(make_pair(curr.first + 1, curr.second + 1));  // ���� Breath �ð��� second �� �����ϰ� + 1�� �߰�
		q.push(make_pair(curr.first - 1, curr.second + 1));
		q.push(make_pair(curr.first * 2, curr.second + 1));

	}

}

int main() {

	cin >> N >> K;
	cout << solve();
	return 0;
}