//https://www.acmicpc.net/problem/15686 

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct position {
	int y, x;
};

int n, m, type, ret;
vector<position> house, shop, pick;

void dfs(int pos) {
	if (pick.size() == m) { //m ���� ġŲ���� ���õǾ��ٸ�

		int candi = 0; // ���� �ּҰ��� �� 

		for (int i = 0; i < house.size(); ++i) { //�� 
			int min_dist = 1000000; // ���� �ּ� ���� ���ϱ� ���� ���
			for (int j = 0; j < pick.size(); ++j) { //ġŲ��
				min_dist = min(min_dist,     //�� ������ ���� ����� ġŲ������ �Ÿ��� ���� �ּҰ� �Ǵ� ���� ����
					abs(house[i].y - pick[j].y) + abs(house[i].x - pick[j].x));
			}
			candi += min_dist;  // 0 ��° ������ ���� ���� �� + 1��° ������ ���� ������ + ...
		}

		if (ret > candi)
			ret = candi;

		return;
	}

	for (int i = pos; i < shop.size(); ++i) {
		pick.push_back(shop[i]); //�ְ� 
		dfs(i + 1);  //������ 
		pick.pop_back(); // Ȯ�������� ���� 
	}
}

int main() {


	cin >> n >> m;

	position target;
	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			cin >> type;
			if (type == 1) {
				target.y = y; target.x = x;
				house.push_back(target);

			}
			else if (type == 2) {
				target.y = y; target.x = x;
				shop.push_back(target);

			}
		}
	}
	ret = 999999;
	dfs(0);
	cout << ret;
	return 0;
}