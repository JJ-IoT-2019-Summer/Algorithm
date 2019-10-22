#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

bool dfs(string from, vector<vector<string>>& tickets, vector<bool>& visited, vector<string>& temp, vector<string>& answer, int cnt)
{
	temp.push_back(from); // �װ����� ��߿����� ��� �迭

	if (cnt == tickets.size()) {
		answer = temp;
		return true;
	}

	for (int i = 0; i < tickets.size(); ++i) {
		if (tickets[i][0] == from && visited[i] == false) { // from�� Ƽ���� ��߿��̰� , �湮���� ���ٸ�
			visited[i] = true; // �湮 ǥ��, tickets ���� �迭�� �����ϴ� ���� �ƴ϶� visited ��� �迭�� �湮���θ� ǥ��

			bool success = dfs(tickets[i][1], tickets, visited, temp, answer, cnt + 1); //�ش� Ƽ���� �������� �̾����� ���Ž��
			if (success) return true; // ��ΰ� �ϼ��Ǿ��ٸ� Ʈ�� ( dfs �� )
			visited[i] = false; // �ƴ϶�� �湮 ǥ�ø� �ٽ� false��
		}
	}

	temp.pop_back(); // �ٸ� ��츦 Ȯ���غ��ƾ� �ϹǷ� ����
	return false;

}


vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer, temp;   //dfs�� ���� ��θ� ��� �迭 temp
	vector<bool> visited(tickets.size(), false);

	sort(tickets.begin(), tickets.end());
	dfs("ICN", tickets, visited, temp, answer, 0);
	return answer;
}