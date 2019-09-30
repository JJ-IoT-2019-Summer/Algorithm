#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

				//�帣 , ��� Ƚ��, �ε��� 
bool compare(tuple<string, int, int>& a, tuple<string, int, int>& b) {
	if (get<1>(a) == get<1>(b))			 // �帣 ������ ���Ƚ���� ���� �뷡 �߿��� 
		return get<2>(a) < get<2>(b);	//���� ��ȣ�� ���� �뷡�� ���� ����
	return get<1>(a) > get<1>(b);		 // �帣 ������ ���� ����� �뷡�� ���� ����
}

vector<int> solution(vector<string> genres, vector<int> plays) {

	vector<int> answer;
	map<string, int>hash;
	map<int, string, greater<int>> check;

	for (int i = 0; i < genres.size(); ++i) {
	
		if (hash.find(genres[i]) == hash.end()) hash[genres[i]] = plays[i];
		else hash[genres[i]] += plays[i]; // hash�� �����ϴ� �帣��� ��� Ƚ���� �߰�
	}
	for (auto it = hash.begin(); it != hash.end(); it++) {
		check[it->second] = it->first;
		//check[���Ƚ��] = �帣
	}

	vector<tuple<string, int, int>> songs; // �帣, ���Ƚ��, �ε���

	for (int i = 0; i < genres.size(); i++) {
		songs.emplace_back(make_tuple(genres[i], plays[i], i)); // push_back ���� ���� emplace_back
	}

	sort(songs.begin(), songs.end(), compare); // �뷡�� ��� Ƚ��, ���� ��ȣ�� ����

	for (auto it = check.begin(); it != check.end(); it++) { // ���Ƚ���� �ε����� check �迭
		int temp = 0;
		for (int j = 0; j < songs.size(); j++) {
			if (get<0>(songs[j]) == it->second) { // ���� �뷡��  check �� ��� �帣���
				answer.emplace_back(get<2>(songs[j])); // ������ �ε����� ���� , ���������̱� ������ ���� �� ����
				temp++;
			}
			if (temp == 2) break;	//���� ����� �뷡�� 2�� ������� Ż��
		}
	}

	return answer;
}

int main() {
	vector<string> genres ;
	genres.push_back("classic");
	genres.push_back("pop");
	genres.push_back("classic");
	genres.push_back("classic");
	genres.push_back("pop");

	vector<int> plays;
	plays.push_back(500);
	plays.push_back(600);
	plays.push_back(150);
	plays.push_back(800);
	plays.push_back(2500);

	vector<int> answer = solution(genres, plays);

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
	return 0;
}