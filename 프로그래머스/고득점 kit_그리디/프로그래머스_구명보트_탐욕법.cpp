//https://programmers.co.kr/learn/courses/30/lessons/42885

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
	int pair = 0;

	int heavy = people.size()-1;
	int light = 0; 
	int weight = limit;

	sort(people.begin(), people.end()); // ���� �������� ����

	while (light < heavy) { 

		if (people[light] + people[heavy] <= limit) { //����� �¿� �� ���� ���
			light++;
			heavy--;
			pair++; // �� ����� �Բ� Ÿ�� ��� 
		}
		else  //���� ���ſ� ��������� �� ���� �¿� �� ���� ��� 
			heavy--; // ���� ���ſ� ����� ȥ�� Ž.
		
	}
	
	return people.size()- pair; // 4�� �� 2���� ¦�̶�� pair�� 1, �� 4-1�� 3���� ��Ʈ
}

int main() {

	vector<int>people{ 70, 50,80, 50 };
	cout << solution(people, 100);
	return  0;
}