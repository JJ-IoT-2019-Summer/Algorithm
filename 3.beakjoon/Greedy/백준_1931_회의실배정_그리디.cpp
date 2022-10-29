#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> v;

int main() {
	cin >> N;
	int start, end = 0;

	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		v.push_back(make_pair(end, start));
	}
	sort(v.begin(), v.end());  // ȸ�� ���� �ð��� ���� ������ ����

	int prev_end = 0;
	int cnt = 0;

	for (int i = 0; i < v.size(); i++) {
		if (prev_end <= v[i].second) {	// ���� ȸ�� ������ �ð����� ȸ�� ���� �ð��� ���ų� �ʴٸ�
			prev_end = v[i].first;      // �̹� ȸ�� ����ð��� prev_end �� ����
			cnt++;						// ȸ�� �� ���� 
		}
	}
	cout << cnt;


}