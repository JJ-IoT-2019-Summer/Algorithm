#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;
	map<string, int> hash;

	for (int i = 0; i < clothes.size(); i++) {
		hash[clothes[i][1]]++;  // �ش� ������ ������ ���� ����
	}

	map<string, int>::iterator it; // map �� ���� �ϱ� ���� iterator

	for (it = hash.begin(); it != hash.end(); it++) {
		answer = answer * (it->second + 1);    // ������ ���� + 1 (�������� ���� ��� )
	}

	return answer - 1; // ��� �������� ���� ���� �����ϹǷ� -1
}