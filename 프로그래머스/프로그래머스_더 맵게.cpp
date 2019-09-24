#include <string>
#include <vector>
#include <queue>
#include <functional> // min_heap ���� ���� ����

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	int first = 0;
	int second = 0;
	priority_queue <int, vector <int>, greater <int> > min_heap; //�߰��� vector �־�� ��, greater �� min heap , less �� max_heap

	for (int i = 0; i < scoville.size(); i++) {
		min_heap.push(scoville[i]);
	}

	while (min_heap.top() < K) {

		if (min_heap.size() == 1) return -1; // �� ���� ���� �� ������ -1 ����

		first = min_heap.top();
		min_heap.pop();
		second = min_heap.top();
		min_heap.pop();

		answer++;
		int new_scoville = first + second * 2;
		min_heap.push(new_scoville);

	}
	return answer;
}