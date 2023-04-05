#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

// A���� M ������ ���� ���� 65 ~ 77 
//N ���� Z ������ �Ʒ� �������� ���� 78 ~ 90
int solution(string name) {
	int answer = 0;
	int size = name.size();
	int direction = name.size() - 1; // �ִ� �̵� Ƚ�� 

	for (int i = 0; i < size; i++) {
		int next = i + 1;
		char target_alp = name[i];

		if (target_alp <= 'N') answer += target_alp - 'A';
		else answer += 'Z' - target_alp + 1;

		while (next < size && name[next] == 'A') next++; 
		//������ �������� �����ϸ鼭 A�� ������ �ǳ� ��

		direction = min(direction, i + size - next + min(i, size - next)); //��� A�� �� ������ ���������� �̵��ϴ� �Ͱ� �������� �̵��ϴ� ���� ������ 
		// i + size - next : �������� ���ư��� �� A�� �ƴ� ���� ���� ������ �̵��� Ƚ��
		//min ( i , n-next ) : ���� ���� �ε����� �ڿ��� ���� ����� A�� �ƴ� �ε��� �� � ���� �� ������ ��
		//��ó https://jayrightthere.tistory.com/entry/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EC%A1%B0%EC%9D%B4%EC%8A%A4%ED%8B%B1
		

	}
	answer += direction;
	return answer;

	//�� �ٸ� ����Ǯ�̷δ� ������ �������� "A"�� �ƴ� ���ڸ� ������ �̵� Ƚ��
	// ���� �������� "A"�� �ƴ� ���ڸ� ������ �̵� Ƚ�� 
	// ���ؼ� �� ���������� �̵��ϰ� "A" ���ڿ� target ������ ���̸� asnwer �� ���ϴ� ��� 
}


int main() {

	string str = "CANAANAA";
	cout << solution(str);
	return 0;

}