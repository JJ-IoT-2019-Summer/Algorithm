//https://programmers.co.kr/learn/courses/30/lessons/42584
#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer(prices.size());
	
	for (int i = 0; i < prices.size(); ++i) { //���� �ֽ� ����
		int cnt = 0;
		for (int j = i+1; j < prices.size(); ++j) { //���� ������ �ֽ� ���ݵ�
			if (prices[i] <= prices[j]) {
				answer[i]++; //������ �϶����� ���� ���
			}
			else { //������ �϶��� ��� 
				answer[i]++;
				break;
			}
		}
	}
	
	return answer;
}

int main()
{
	vector<int> p({ 1,2,3,2,3 });
	vector<int> result = solution(p);

	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " ";

	return 0;
}