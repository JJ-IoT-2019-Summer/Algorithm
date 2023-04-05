////https://programmers.co.kr/learn/courses/30/lessons/42746

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(string &a, string &b) {
	return a + b > b + a ? true : false;
}


string solution(vector<int> numbers) {
	string answer = "";
	vector<string> string_arr;
	for (int i = 0; i < numbers.size(); ++i) // ���ڸ� ��Ʈ�����ͷ� ��ȯ
		string_arr.push_back(to_string(numbers[i]));

	sort(string_arr.begin(), string_arr.end(), compare);
	//���͸� ������ �ڸ����� ū �������� �������� ����

	for (string i : string_arr) //���� �ڸ����� ū������ ���ڿ��Է�
		answer += i;


	if (answer[0] == '0') return "0"; //���� ū ���� 0�̸�, "0"��ȯ
	return answer;
}