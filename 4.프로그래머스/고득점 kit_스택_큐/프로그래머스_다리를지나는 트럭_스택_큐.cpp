//https://programmers.co.kr/learn/courses/30/lessons/42583

#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <numeric> //accumulate�� ���� ���� ���
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	vector<int> bridge;

	for (int i = 0; i < bridge_length; ++i)
		bridge.emplace_back(0); // push ���� ���� emplace_back, �ٸ��� ���̸�ŭ 0���� ä��

	while (!bridge.empty()) { //�ٸ��� ���� 
		answer++;	//�ð� ���� 
		bridge.erase(bridge.begin()); //���� �ϳ� ���� ( Ʈ�� �ϳ��� ����ϱ� ������ )

		if (truck_weights.size() > 0) { // ��� Ʈ���� �����ϸ�
			int sum = accumulate(bridge.begin(), bridge.end(), 0); // �ٸ��� �ǳʴ� Ʈ���� ���� ��
			if (sum + truck_weights[0] <= weight) { // �ǳʴ� Ʈ���� ���Ʈ���� ���Ը� ���� ���Ը� �ߵ� �� ������
				bridge.emplace_back(truck_weights[0]); // ��� Ʈ���� �ٸ��� �ø�
				truck_weights.erase(truck_weights.begin()); //��� Ʈ���� ��Ͽ��� ����
			}
			else {
				bridge.emplace_back(0); // ���Ʈ���� �ö���� ���ϸ� 0�� �ڿ� ����
			}
		} // �ٸ��� ���̸�ŭ �ð��� ����ؾ��ϱ� ������ ��� Ʈ���� �������� �ʾƵ� 
		//��� �ݺ����� ���� �ٸ��� �ǳʴ� Ʈ���� ��� ���������� �ð�����
	}

	return answer;
}

int main() {

	int length = 2;
	int weight = 10;
	vector<int> truck{ 7,4,5,6 };
	cout << solution(length, weight, truck);
	return 0;
}