#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

int N;
int arr[1001] = { 0, };
vector<int> sum;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N); // ���� �̴µ� �ɸ��� �ð��� �������� ����

	sum.push_back( arr[0] ); // ���� ���� ���� ���� �� �ִ� ����� �ҿ� �ð�
	for (int i =1; i < N; i++) 
		sum.push_back( sum[i - 1] + arr[i]); // ���� ��� �ð� + �ڱ��� ATM �ҿ� �ð�
	 
	cout << accumulate(sum.begin(), sum.end(), 0); // �հ� 
	
	return 0;
}