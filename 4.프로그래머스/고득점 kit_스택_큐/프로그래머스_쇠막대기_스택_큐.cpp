//https://programmers.co.kr/learn/courses/30/lessons/42585
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;


int solution(string arrangement) {

	stack<char> s;
	int answer = 0;

	for (int i = 0; i < (int)arrangement.size(); ++i) {
		if (arrangement[i] == '(')  //�������� �� ���� 
			s.push('(');

		else {
			s.pop();
			if (arrangement[i - 1] == ')')
				answer += 1;

			// ')' ���� ���ڰ� ')' �̸� ���� ���ڰ� �������� �� �κ� �߰� +1

			else if (arrangement[i - 1] == '(')
				answer += (int)s.size();

			// ')' ���� ���ڰ� ')' ���� �� ���� ���ڰ�  '(' �̸� -> ������ stack �����ŭ +
			// �������� �������� ������ŭ �и� 

		}
	}
	return answer;
}

int main()
{
	string str = "(((()(()()))(())()))(()())";
	cout << solution(str);
	return 0;
}