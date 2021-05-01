//https://www.acmicpc.net/problem/16235

#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

struct TREE{
	int y, x, age;

};

bool cmp(TREE& a, TREE&b) {
	return (a.age < b.age); // ������ ���̰� ������� ����
	//�ʱ� ���� �Է��� ���Ŀ� ���
}

struct QUEUE {
	int f, b; //front, back
	TREE tree[684000];

	QUEUE() {
		init();
	}
	void init() {
		f = 0;
		b = 0;
	}
	bool isempty() {
		return (f == b); 
	}
	void push(TREE val) {
		tree[b++] = val; // �ǵڿ� �߰��ϰ� b ����
	}
	void pop() {
		++f;
	}
	TREE front() {
		return tree[f];
	}
	int size() {
		return (b - f);
	}

};
const int MAX = 100;

int n, m, k;
QUEUE tree[2];

TREE init_tree[100]; //�ʱ� �Է¹޴� Ʈ��
QUEUE new_tree; //�ʱ⿡�� �ƹ��͵� ���� �����ϰ� �Ǹ� ���⿡ ����
QUEUE dead_tree, birth_of_child_tree; // ���� ���� ������ ť�� ������ ������ ������ ť

int map[10][10], add[10][10];
//����� ������ map �迭 , �߰����� ����� ������ add �迭
int main() {

	cin >> n >> m >> k;    

	//N X N
	//m�� �ٿ��� ���� ������ ������ ��Ÿ���� x,y,z (x,y)�� ��ġ z�� ����
	//k �� ��� �Ŀ��� ����ִ��� 

	for (int y = 0; y < n; ++y) {
		for (int x = 0; x < n; ++x) {
			cin >> add[y][x];
			map[y][x] = 5;

		}
	}
	for (int i = 0; i < m; ++i) { //�ʱ� ���� ���� �Է�
		cin >> init_tree[i].y >> init_tree[i].x >> init_tree[i].age;
		init_tree[i].y--, init_tree[i].x--; // �迭�� 0���� ����ϱ� ������ �ϳ� ����
	}

	sort(init_tree, init_tree + m, cmp); //������ ���̰� �����ͺ��� ū�ͱ���
	
	int cur = 0, next = 0;
	for (int i = 0; i < m; ++i) {
		tree[cur].push(init_tree[i]); //cur Ʈ������ ���̰� � �������� ���� 
	}

	

	for (int i = 0; i < k; ++i) { // 0���� k�����

		next = (cur + 1) % 2; // ���簡 0 �̸� next�� 1
						     // next�� ���簡 �Ǹ� cur �� 1, next�� 0�� ��
							 //�迭 2���� ����, ������ ������ ���� ���
		
		dead_tree.init();
		birth_of_child_tree.init(); // main ���� ť�� �����ϸ� stack�� ���̹Ƿ� ū �迭�� ��������
		tree[next].init();			//�۷ι����� �����Ͽ� ���� ����ؾ��� 

		while (!new_tree.isempty()) { //� �������� ������
			TREE cur_tree = new_tree.front(); new_tree.pop();

			if (map[cur_tree.y][cur_tree.x] >= cur_tree.age) { //��� ���� �� �ִ� Ʈ��, ���̺��� ����� ���� 
				map[cur_tree.y][cur_tree.x] -= cur_tree.age; //����� ��������Ƿ� ������Ʈ

				++cur_tree.age; //�������� �������� ���̸� �ѻ�ø�
				tree[next].push(cur_tree); //�ؽ�Ʈ Ʈ���� ���� (�����⵵�� ����ϴ� ����)

			}
			else 
				dead_tree.push(cur_tree); // ������ �������Ƿ� ���� ���� ť�� ����

			
		}

		while (!tree[cur].isempty()) { //������ ����ִ� ���� ������
			TREE cur_tree = tree[cur].front(); tree[cur].pop();

			if (map[cur_tree.y][cur_tree.x] >= cur_tree.age) { //��� ���� �� �ִ� Ʈ��, ���̺��� ����� ���� 
				map[cur_tree.y][cur_tree.x] -= cur_tree.age; //��� ���

				++cur_tree.age; //�������� �������� ���̸� �ѻ�ø�
				tree[next].push(cur_tree); //�ؽ�Ʈ Ʈ���� ����

				if ((cur_tree.age % 5) == 0)   //������ ������ Ʈ��, ���̰� 5�� ����� ������ ���� ������ ���� ť�� �߰�
					birth_of_child_tree.push(cur_tree);				

			}
			else 
				dead_tree.push(cur_tree); // ������ �������Ƿ� ���� ���� 

			
		}

		while (!dead_tree.isempty()) { //������ ����, ���� ������ Ȯ��
			TREE cur_tree = dead_tree.front(); dead_tree.pop();
			map[cur_tree.y][cur_tree.x] += (cur_tree.age / 2); // ������ �ִ� ĭ�� ������� �߰�
		}

		const int dy[] = { -1,-1,-1,0,0,+1,+1,+1 };
		const int dx[] = { -1,0,+1,-1,+1,-1,0,+1 };  //�ȹ���

		new_tree.init(); // ����ϱ� ���� �ʱ�ȭ �ѹ�
		while (!birth_of_child_tree.isempty()) { //������ �Ǹ� ����
			TREE cur_tree = birth_of_child_tree.front(); birth_of_child_tree.pop(); //���� ������ ������
			for (int dir = 0; dir < 8; ++dir) {  //8��������
				TREE next_tree;  
				next_tree.y = cur_tree.y + dy[dir];
				next_tree.x = cur_tree.x + dx[dir];
				next_tree.age = 1;  //1��¥�� ���� 

				if (next_tree.y < 0 || next_tree.y >= n || next_tree.x < 0 || next_tree.x >= n) continue;

				new_tree.push(next_tree); //�� ��¥�� ���� ����(���ο� ���� ť�� ����)
			}
		}

		for (int y = 0; y < n; ++y) { //�ܿ￡ �� �� 
			for (int x = 0; x < n; ++x) {
				map[y][x] += add[y][x]; //�Է¹��� ��� �߰�
			}
		}

		cur = next; // �ذ� �ٲ�����Ƿ� ���� queue���� ������ ��


	}
	cout << tree[next].size() + new_tree.size() << endl;
	
	return 0;

}