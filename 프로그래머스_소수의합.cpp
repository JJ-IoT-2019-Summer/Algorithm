#include <iostream>
#include <vector>
using namespace std;

//2���� N������ ��� �Ҽ��� ���� ���ϼ���.N�� 7�̶��{ 2,3,5,7 } = 17�� ��� �Ͻø� �˴ϴ�.
//N�� ������ 2�̻� 10, 000, 000���� �Դϴ�.ȿ���� �׽�Ʈ�� ��� �ð� ������ 1���Դϴ�.
//�Ҽ��� �տ� ���� �˰����� '�Ƹ��佺�׳׽��� ü'

//�Ҽ� ã���� ��쿡��
//N = A * B �� �Ҽ��� �ƴ��� �̿�
//��, � ���� n�� �����ٱ����� �� �� �� ���� ���� ���ؼ��� ����������� �Ҽ��� �ƴϴ�.
//
//int rootNumber = sqrt(number); 
//for (int n = 3; n <= rootNumber; n += 2) 
//	if (number % n == 0)  return false;
//

int main() {

	int n = 0;
	cin >> n;
	long long answer = 0;
	vector<bool> arr(n + 1);

	for (int i = 2; i <= n; ++i) {
		if (arr[i] == false) answer += i; // ������ üũ�� �� �Ǿ��ִٸ�, �ջ꿡 ���� ���� ����


		for (int j = i; j <= n; j += i)    // i�� 2�� �� 2,4,6,8 ... 2�� ��� �ε����� ��� true��
			arr[j] = true;
		
	}
	cout << answer;
	return 0;
}

