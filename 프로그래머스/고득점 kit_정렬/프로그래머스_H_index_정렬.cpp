#include <string>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
	int answer = 0; // 6 5 3 1 0 6 �� �����ͼ� 6���̻� �ο�ȳ� 6�� ã��
				 //������ ���� 6�� �����ο�Ȱ� ã��


	sort(citations.begin(), citations.end(), greater<int>());
	int  j = 0;
	for (int i = 0; i < citations.size(); i++) { //n���� �� ��
		int h = citations[i]; // h�� 

		if (citations[j] <= j) break; // h�� �̻� �ο�� ���̶�� 
		j++;

	}
	return j;
}