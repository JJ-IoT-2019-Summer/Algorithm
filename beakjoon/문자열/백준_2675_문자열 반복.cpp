#include <iostream>
#include <string>

using namespace std;


//���ڿ� S�� �Է¹��� �Ŀ�, �� ���ڸ� R�� �ݺ��� �� ���ڿ� P�� ���� �� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
//��, ù ��° ���ڸ� R�� �ݺ��ϰ�, �� ��° ���ڸ� R�� �ݺ��ϴ� ������ P�� ����� �ȴ�.S���� QR Code "alphanumeric" ���ڸ� ����ִ�.
//
//QR Code "alphanumeric" ���ڴ� 0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\$%*+-. / : �̴�.


int T;

int main() {
	string str;
	int rep;
	char ch[1000];
	cin >> T;

	for (int i = 0; i < T; ++i) {
		cin >>rep >> str;

		for (int i = 0; i < str.size(); i++) {
			char cur = str[i]; //�� ���ڿ� ���� 
			for (int j = i*rep; j < i*rep+rep; j++) {   //1~rep , rep + 1 ~ 2rep...
				ch[j] = cur;
				cout << ch[j];
			}

		}
		cout << endl;
	}
	return 0;
}