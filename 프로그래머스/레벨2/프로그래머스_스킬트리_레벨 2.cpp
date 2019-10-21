#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool check(const string& tree, const string& skill) {
	bool broken = false;
	int prev = 0;
	for (auto s : skill) {  //�� ��ų�� ���ؼ�
		int cur_index = tree.find(s); //������ ��ųƮ������ ��ų��ġ ã��
		if (cur_index != -1) { //��ųƮ���� ��ų�� �������� ������
			if (broken || cur_index < prev) return false;
			//���� ��ųƮ���� ������ ��� ��ų���� ����������ϴ� ��ų�̶��
			//false
			else prev = cur_index;
		}
		else {
			broken = true; //ù ��° ��ų�� �������� ������,
						//���� ��ų�� ��ųƮ���� �����ϹǷ� return false

		}
	}
	return true;

}


int solution(string skill, vector<string> skill_trees) {
	int answer = 0;

	for (auto tree : skill_trees) { // �������� ��ųƮ�� Ȯ��
		if (check(tree, skill)) ++answer; // ������ ��ųƮ���� ������ ��Ȯ�ϴٸ� ����
	}
	return answer;
}

