#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
using namespace std;

int main() {


	string input;
	string temp = "";
	int result=0;
	bool minus = false;

	cin >> input;

	for (int i = 0; i <= input.size(); i++) {
		if (input[i] == '+' || input[i] == '-' || input[i] == NULL) {
			if (minus == true) result -= stoi(temp);
			else result += stoi(temp); //ó�� - �� �����ų�, +�� ������� ������ �ִ� ���� result �� ����
			temp = "";
			if (input[i] == '-') minus = true; // ù '-' ���� '+'���� �й� ��Ģ���� -�� �ǰ� ���� '-'�� ������ ��ȣ�� �ݰ� �ٽ� ���� ������ 
												//��� minus �� �� => true 
			

		}
		else  // ���� �� ��� 
			temp += input[i]; // �ӽ÷� �����ϴ� temp �� ���� �Է�
				
	}
	cout << result;



	return 0;
}