#include <iostream>
#include <string>
#include <cstring>

using namespace std;

//���ĺ� ��ҹ��ڷ� �� �ܾ �־�����, �� �ܾ�� ���� ���� ���� ���ĺ��� �������� �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�.
//��, �빮�ڿ� �ҹ��ڸ� �������� �ʴ´�.

int arr[26];
int main()
{
	string str;
	char cur;
	int max = -1;
	int index = -1;
	bool flag = false;

	memset(arr, 0, sizeof(arr));

	cin >> str;

	for (int i = 0; i < str.size(); ++i) {
		if (islower(str[i]))       //�ҹ����̸�?
			cur = toupper(str[i]); //�빮�ڷ� ��ȯ
		else 
			cur = str[i];
		
		int num(cur); // �ƽ�Ű ���ڷ� ��ȯ
		arr[cur - 65]++;

	}

	for (int i = 0; i < 26; i++) { //���ĺ� a ���� z ����
		if (max < arr[i]) {  
			max = arr[i]; // �ִ� �󵵼��� ���� ���ĺ� �̶��
			index = i + 65; // ���� ���ĺ� + 65 �� �빮�� �ƽ�Ű �ڵ� ����
			flag = false; // ������ ���� x
		}
		else if (max == arr[i]) { //���� ���� ���� ���ĺ��� ������ �����ϸ�  flag�� true
			flag = true;
		}
	}
	
	
	if (flag) cout << "?";
	else {
		char result(index); // �ƽ�Ű �ڵ�� �빮�� ����
		cout << result;
	}

}
