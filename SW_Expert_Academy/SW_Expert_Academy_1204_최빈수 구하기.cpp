#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int arr[1000];
int result[1000];
int T;

int main()
{
	int a, b;
	int max, maxIndex=0;

	cin >> T;
	for (int i = 0; i < T; ++i) {
		memset(arr, 0, sizeof(arr));

		cin >> a;
		for (int j = 0; j < 1000; ++j){
			cin >> b;
			arr[b]++;  //�󵵼� ����
		}

		max = 0;
		maxIndex = 0;
		for (int k = 0; k < 1000; ++k) {
			if (arr[k] >= max) {  // �ֺ󵵼� ���� ���� ã��. �󵵰� ������ 
								// ū ���ڸ� ����ϱ� ���� 0���� 1000 ������
				max = arr[k];   // �ֺ� �� arr[k]
				maxIndex = k;   // �� �ε���
			}
		}

		cout << "#" << a << " " << maxIndex;
		if (i != 9) cout << endl;

	}
}