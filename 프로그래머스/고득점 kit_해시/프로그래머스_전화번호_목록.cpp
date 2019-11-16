//https://programmers.co.kr/learn/courses/30/lessons/42577
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {

	bool answer = true;
	for (string s1 : phone_book) { // �迭 �ε��� ���ͷ����� ��� ��� ����!
		for (string s2 : phone_book) {
			if (s1 != s2) { // �ٸ� ����
				if (s1.length() > s2.length()) { // s1 �� ũ�Ⱑ ũ�鼭
					if (s2 == s1.substr(0, s2.length())) //s1���� 0���� s2 ũ�⸸ŭ �������� �� s2�� ���ٸ�
						return false;
				}
			}
		}
	}
	return answer;
}