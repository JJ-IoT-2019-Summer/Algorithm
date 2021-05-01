//https://programmers.co.kr/learn/courses/30/lessons/12915#

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(pair<char, string>&a, pair<char, string>&b) {
	return a < b; //n��° �ε��� ���ڰ� �ٸ� ��� ���������� ������ ����
				   //���� ��� ���ڿ� ��ü������ ������ ����
}
vector<string> solution(vector<string> strings, int n) {
	vector<string> answer;
	vector <pair<char, string>> temp;

	for (auto i : strings)
		temp.push_back({ i[n],i });

	sort(temp.begin(), temp.end(), cmp);

	for (int i = 0; i < temp.size(); ++i)
		answer.push_back(temp[i].second);

	return answer;
}