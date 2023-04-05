#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
	bool answer = true;
	stack <char> st;
	for (int i = 0; i < s.size(); i++) {
		char cur = s[i]; // ���� ����
		if (cur == '(') { // ( '(' ��� ������ ��� 
			st.push(cur);
		}
		else { // ( ')' ��� ������ ��� 
			while (!st.empty() && st.top() != '(') { // ������ ������� �ʾҰ�, '(' �� �ƴ϶��
				st.pop(); //'(' �� ���ö����� pop
			}
			if (st.empty()) return false; //¦�� ������ ���� ����
			st.pop(); // ¦�� ������  �� '(' �� ����߱� ������ pop
		}
	}
	if (!st.empty()) return false;

	return answer;
}