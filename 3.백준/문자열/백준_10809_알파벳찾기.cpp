#include <iostream>
#include <string>
#include <cstring>

//���ĺ� �ҹ��ڷθ� �̷���� �ܾ� S�� �־�����.������ ���ĺ��� ���ؼ�,
//�ܾ ���ԵǾ� �ִ� ��쿡�� ó�� �����ϴ� ��ġ��, ���ԵǾ� ���� ���� ��쿡�� - 1�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

int alpha[26] = { -1, };

using namespace std;

int main() {
	memset(alpha, -1, sizeof(alpha));
	string str;

	cin >> str;

	char alp = 'a';
	int k = 0;

	while (k<26) {
	for (int i = 0; i < str.size(); i++) {
			if (alp == str[i]) { // ó�� ������ ���� ����
				alpha[k] = i; // ������ ��ġ ����
				break;
			}
		}

		alp++; // ���� ���� Ȯ��
		k++; // k ���� 
	}

	for (int i = 0; i < 26; i++) {
		cout << alpha[i] << " ";
	}

	
	return 0;
}