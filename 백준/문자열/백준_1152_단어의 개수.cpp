#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

char arr[1000000];
string str;
int cnt;

int main() {

	getline(cin, str);
	
	strcpy(arr, str.c_str()); // strtok �� ����ϱ� ���� arr�� ����

	char* tok = strtok(arr, " "); // �������� ���� �и� (�չ����� tok����)
	while (tok != NULL) {
		tok = strtok(NULL, " "); //�������� ���� �и� 
		cnt++;
	}
	cout << cnt;
	return 0;
}