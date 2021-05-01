//https://programmers.co.kr/learn/courses/30/lessons/42576

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	sort(participant.begin(), participant.end()); // ������ �������� ����
	sort(completion.begin(), completion.end()); // ������ �������� ����

	for (int i = 0; i < completion.size(); i++) {  //������ ��� Ȯ��
		if (participant[i] != completion[i]) { // ������ ����̶� ������ ����̶� �ٸ��ٸ�
											//(������������) �̰� ũ�Ⱑ 1����
			return participant[i];          //�����ڿ� �ִ� ����� �������� ���� ��
		}
	}

	return participant[participant.size() - 1];   // ���ĵ� ������ �� ������ �����ڰ� �������� ����
}