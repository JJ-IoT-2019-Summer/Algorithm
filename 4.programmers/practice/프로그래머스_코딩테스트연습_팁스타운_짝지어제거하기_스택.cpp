//https://programmers.co.kr/learn/courses/30/lessons/12973
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
	int answer = 0;
	stack<char> st;

	for (int i = 0; i < s.size(); ++i) {
		if (st.empty() || st.top() != s[i]) { //������ ����ְų�, ž�� ���� ���ڰ� �ٸ��ٸ�
			st.push(s[i]); //���繮�ڸ� �������� 
		}
		else { //�� ���ڰ� ¦
			st.pop();
		}
	}

	if (st.empty()) answer = 1;

	return answer;
}