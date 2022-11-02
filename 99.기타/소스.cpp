#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	int a;
	int b;
	int message_t = 0;
	int time = 1;
	int check = 0;

	queue<int> q;

	bool working[11] = { false, }; //�����ӵ�
	int working_time[11] = { 0, }; //���� �� �ð�

	cin >> a >> b;   //a �� �޼��� �� , b�� ������ ��

	for (int i = 0; i < a; i++) {   //�޼����� ť�� ����
		cin >> message_t;
		q.push(message_t);
	}

	while (1) {                  //�����Ӱ� ���� �ϰ� ���� ����
		check = 0;

		for (int i = 0; i < b; i++) {     // �����ӵ�

			if (working[i] == false && q.size() > 0) {      // �����Ӱ� ���� �ϰ� ���� ������
				working[i] = true;
				working_time[i] = q.front();  // ���� ������
				q.pop();
			}

			if (working[i] == true) { // �����Ӱ� ���� �ϰ� ������
				working_time[i]--;  //�ð� ����
				if (working_time[i] == 0) working[i] = false; // 0�� �Ǹ� ���� �� ���� �غ�
			}

			if (working[i] == false)   // ������ ���� ������ üũ
				check++;

		}

		if (check == b) { // ��� �Ͼ��ϰ� ������ ��
			break;
		}

		time++;
	}



	cout << time << endl;
	return 0;
}